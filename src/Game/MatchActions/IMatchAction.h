#pragma once

class World; // forward-declaration;
class PlayersHolder; // forward-declaration;
class Fortuna; // forward-declaration;
class GameIO; // forward-declaration;

class IMatchAction {
public:
    struct Context {
        World* world;
        PlayersHolder* players_holder;
        Fortuna* fortuna;
        GameIO* io; 
    };

    virtual ~IMatchAction() = default;

    virtual void Execute(Context* context) const = 0;
};
