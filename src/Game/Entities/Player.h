#pragma once

#include <Game/CardUtilities/CardCollection.h>

using PlayerId = uint32_t;

class Player {
public:
    Player();

    void AddCard();

private:
    CardCollection hand_;
};
