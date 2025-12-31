#include "EndTurnAction.h"

#include <Game/Runtime/PlayersHolder.h>
#include <Game/Runtime/GameIO.h>
#include <Game/Entities/World.h>
#include <Game/Cards/CardsConstants.h>
#include <Utils/Exceptions.h>

namespace {

static const std::string kLostMessage = "lost";
static const std::string kWonMessage = "won";

void ProcessLostPlayer(PlayersHolder* players, PlayerId who_lost, bool* is_game_over_flag, GameIO* io) {
    players->GetPlayer(who_lost)->MarkAsLost();
    io->SendInfo(who_lost, kLostMessage);
    const auto players_left = players->GetNotLostPlayers();
    if (players_left.size() == 1) {
        *is_game_over_flag = true;
        io->SendInfo(players_left[0], kWonMessage);
    }
}

}

EndTurnAction::EndTurnAction() = default;

void EndTurnAction::Execute(Context* context, PlayerId owner, PlayerId target) const {
    if (owner) {
        throw Exception("EndTurnAction::Execute: has owner");
    }

    if (!context->players_holder->CanTurnEndWithoutDraw()) {
        auto* player = context->players_holder->GetPlayer(target);
        auto drawn_card = context->world->GetDeck().TakeCardAt(0);

        if (drawn_card->GetTypeId() == cards_constants::kExplosiveCatCardTypeId) {
            const auto defuse_cards = player->GetHand()->GetAllCardsOfType(cards_constants::kDefuseCardTypeId);

            if (defuse_cards.empty()) {
                ProcessLostPlayer(context->players_holder, target, context->is_game_over, context->io);
                return;
            } else {
                const size_t defuse_card_index = player->GetHand()->GetIndexById(defuse_cards[0]->GetCardId());
                auto defuse_card = player->GetHand()->TakeCard(defuse_card_index);
                context->world->GetDiscardDeck().PlaceOnTop(defuse_card);

                const auto new_explosive_cat_pos = context->io->AskForPlace(target);
                context->world->GetDeck().PlaceAt(drawn_card, new_explosive_cat_pos);
            }
        }

        player->GetHand()->InsertCard(drawn_card);
        context->io->SendCards(target, player->GetHand()->GetAllCards());
    }
    
    context->players_holder->SetWetherTurnCanEndWithoutDraw(false);

    const size_t turns_left = context->players_holder->GetTurnsForPlayer(target);
    context->players_holder->SetTurnsForPlayer(target, turns_left - 1);

    size_t next_player = target;
    if (turns_left == 1) {
        context->players_holder->HandOver();
    }
}
