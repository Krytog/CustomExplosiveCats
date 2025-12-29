#include "Runtime.h"

#include <Game/MatchActions/IMatchAction.h>
#include <Game/MatchActions/GameInitAction.h>

#include <memory>

Runtime::Runtime(size_t seed, GameIO* game_io, size_t player_count)
 : tech_systems_({.io = game_io, .fortuna = Fortuna(seed)}), game_systems_({.card_resolver_ = CardResolver(&state_machine_.match_log)}) {
    for (size_t i = 0; i < player_count; ++i) {
        (void)game_systems_.players_holder.AddPlayer();
    }
    state_machine_.match_log.AddEntry(MatchLog::LogEntry{
        .action = std::make_unique<GameInitAction>(),
        .owner = 0,
        .target = 0,
    });
}

void Runtime::RunGameLoop() {
    IMatchAction::Context context{
        .world = &game_systems_.world,
        .players_holder = &game_systems_.players_holder,
        .card_resolver = &game_systems_.card_resolver_,
        .fortuna = &tech_systems_.fortuna,
        .io = tech_systems_.io,
    };
    while (true) {
        if (state_machine_.log_to_apply_index >= state_machine_.match_log.GetSize()) {
            continue; // back off
        }

        auto& log_entry = state_machine_.match_log.GetLogEntry(state_machine_.log_to_apply_index);
        log_entry.action->Execute(&context, log_entry.owner, log_entry.target);

        ++state_machine_.log_to_apply_index;
    }
}
