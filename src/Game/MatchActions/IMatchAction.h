#pragma once

#include <Game/Entities/Player.h>

class World; // forward-declaration;
class PlayersHolder; // forward-declaration;
class CardResolver; // forward-declaration;
class Fortuna; // forward-declaration;
class GameIO; // forward-declaration;

class IMatchAction {
public:
    struct Context {
        World* world;
        PlayersHolder* players_holder;
        CardResolver* card_resolver;
        Fortuna* fortuna;
        GameIO* io;
        bool* is_game_over;
    };

    virtual ~IMatchAction() = default;

    virtual void Execute(Context* context, PlayerId owner, PlayerId target) const = 0;
};
