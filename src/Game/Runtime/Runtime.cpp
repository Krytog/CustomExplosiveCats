#include "Runtime.h"

#include <Game/Rules/Initialization.h>
#include <Game/Rules/IMatchAction.h>

Runtime::Runtime(size_t seed, GameIO* game_io, size_t player_count) : tech_systems_({.io = game_io, .fortuna = Fortuna(seed)}) {
    for (size_t i = 0; i < player_count; ++i) {
        (void)game_systems_.players_holder.AddPlayer();
    }
}

void Runtime::RunGameLoop() {
    while (true) {
        if (state_machine_.unfreeze_ts && *state_machine_.unfreeze_ts > std::chrono::steady_clock::now()) {
            continue; // back off
        }
        if (state_machine_.log_to_apply_index >= state_machine_.match_log.GetSize()) {
            continue;
        }
        auto& log_entry = state_machine_.match_log.GetLogEntry(state_machine_.log_to_apply_index);
        log_entry.action->Execute();
        ++state_machine_.log_to_apply_index;
    }
}
