#pragma once

#include <Game/Entities/World.h>
#include <Game/Runtime/PlayersHolder.h>
#include <Game/Runtime/MatchLog.h>
#include <Game/Runtime/GameIO.h>

#include <Contrib/MOLS/src/Game/Fortuna/Fortuna.h>

#include <chrono>
#include <optional>

class Runtime {
public:
    struct GameSystems {
        World world;
        PlayersHolder players_holder;
    };

    struct TechSystems {
        GameIO* io;
        Fortuna fortuna;
    };

    struct StateMachine {
        MatchLog match_log;
        size_t log_to_apply_index;
        std::optional<std::chrono::time_point<std::chrono::steady_clock>> unfreeze_ts;
    };

    Runtime(size_t seed, GameIO* game_io, size_t player_count);

    void RunGameLoop();

private:
    GameSystems game_systems_;
    TechSystems tech_systems_;
    StateMachine state_machine_;
};
