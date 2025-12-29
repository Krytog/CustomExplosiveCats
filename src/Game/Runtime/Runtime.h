#pragma once

#include <Game/Entities/World.h>
#include <Game/Runtime/PlayersHolder.h>
#include <Game/Runtime/MatchLog.h>
#include <Game/Runtime/GameIO.h>
#include <Game/Runtime/CardResolver.h>

#include <Contrib/MOLS/src/Game/Fortuna/Fortuna.h>

class Runtime {
public:
    struct GameSystems {
        World world;
        PlayersHolder players_holder;
        CardResolver card_resolver_;
    };

    struct TechSystems {
        GameIO* io;
        Fortuna fortuna;
    };

    struct StateMachine {
        MatchLog match_log;
        size_t log_to_apply_index;
    };

    Runtime(size_t seed, GameIO* game_io, size_t player_count);

    void RunGameLoop();

private:
    StateMachine state_machine_;
    TechSystems tech_systems_;
    GameSystems game_systems_;
};
