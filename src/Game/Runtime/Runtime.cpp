#include "Runtime.h"

#include <Game/MatchActions/IMatchAction.h>
#include <Game/MatchActions/GameInitAction.h>
#include <Game/MatchActions/StartTurnAction.h>
#include <Game/MatchActions/EndTurnAction.h>
#include <Game/MatchActions/CardSubmitAction.h>
#include <Game/Cards/CardsConstants.h>

#include <memory>
#include <thread>

Runtime::Runtime(size_t seed, GameIO* game_io, size_t player_count)
 : tech_systems_({.io = game_io, .fortuna = Fortuna(seed)}), game_systems_({.card_resolver_ = CardResolver(&state_machine_.match_log), .is_game_over_ = false}) {
    for (size_t i = 0; i < player_count; ++i) {
        (void)game_systems_.players_holder.AddPlayer();
    }

    state_machine_.match_log.AddEntry(MatchLog::LogEntry{
        .action = std::make_unique<GameInitAction>(),
        .owner = 0,
        .target = 0,
    });
    
    game_systems_.players_holder.SetWhoseTurn(1);
    game_systems_.players_holder.SetTurnsForPlayer(1, 1);

    state_machine_.match_log.AddEntry(MatchLog::LogEntry{
        .action = std::make_unique<StartTurnAction>(),
        .owner = 0,
        .target = 1,
    });
}

void Runtime::RunGameLoop() {
    IMatchAction::Context context{
        .world = &game_systems_.world,
        .players_holder = &game_systems_.players_holder,
        .card_resolver = &game_systems_.card_resolver_,
        .fortuna = &tech_systems_.fortuna,
        .io = tech_systems_.io,
        .is_game_over = &game_systems_.is_game_over_,
    };
    while (true) {
        if (state_machine_.log_to_apply_index >= state_machine_.match_log.GetSize()) {
            game_systems_.card_resolver_.TryToResolve(std::chrono::steady_clock::now());
        }

        if (state_machine_.log_to_apply_index >= state_machine_.match_log.GetSize()) {
            const auto intention = tech_systems_.io->FetchSubmitIntention();
            if (intention) {
                ApplyIfSubmitIntentionIsValid(*intention);
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                continue;
            }
        }

        while (state_machine_.log_to_apply_index < state_machine_.match_log.GetSize()) {
            auto& log_entry = state_machine_.match_log.GetLogEntry(state_machine_.log_to_apply_index);
            log_entry.action->Execute(&context, log_entry.owner, log_entry.target);

            ++state_machine_.log_to_apply_index;
        }
    }
}

void Runtime::ApplyIfSubmitIntentionIsValid(const GameIO::SubmitIntention& intention) {
    if (!intention.card.has_value()) {
        if (intention.player == game_systems_.players_holder.GetWhoseTurn() &&
            !game_systems_.card_resolver_.HasAnythingToResolve()) {
            ScheduleTurnTransit();
        }
        return;
    }

    const Player* player = game_systems_.players_holder.GetPlayer(intention.player);
    if (!player->GetHand()->HasGivenId(*intention.card)) {
        return;
    }
    const size_t card_index = player->GetHand()->GetIndexById(*intention.card);
    const auto& card = player->GetHand()->GetCardAsShared(card_index);

    if (card->GetTypeId() == cards_constants::kDenyCardTypeId) {
        if (game_systems_.card_resolver_.HasAnythingToResolve() &&
            game_systems_.card_resolver_.GetWhoseResolveOnTop() != intention.player) {
            state_machine_.match_log.AddEntry(MatchLog::LogEntry{
                .action = std::make_unique<CardSubmitAction>(card),
                .owner = intention.player,
                .target = 0,
            });
        }
        return;
    }

    if (intention.player != game_systems_.players_holder.GetWhoseTurn()) {
        return;
    }

    if (cards_constants::IsCardPlayable(card->GetTypeId())) {
        if (!game_systems_.card_resolver_.HasAnythingToResolve()) {
            state_machine_.match_log.AddEntry(MatchLog::LogEntry{
                .action = std::make_unique<CardSubmitAction>(card),
                .owner = intention.player,
                .target = intention.target,
            });
        }
    }
}

void Runtime::ScheduleTurnTransit() {
    const PlayerId who_ended_turn = game_systems_.players_holder.GetWhoseTurn();
    state_machine_.match_log.AddEntry(MatchLog::LogEntry{
        .action = std::make_unique<EndTurnAction>(true),
        .owner = 0,
        .target = who_ended_turn,
    });
    state_machine_.match_log.AddEntry(MatchLog::LogEntry{
        .action = std::make_unique<StartTurnAction>(),
        .owner = 0,
        .target = game_systems_.players_holder.GetNextPlayerId(who_ended_turn),
    });
}
