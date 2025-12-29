#pragma once

#include <Game/CardUtilities/CardCollection.h>

using PlayerId = uint32_t;

class Player {
public:
    Player(PlayerId id);

    [[nodiscard]] CardCollection* GetHand() noexcept;

    [[nodiscard]] const CardCollection* GetHand() const noexcept;

    [[nodiscard]] PlayerId GetId() const noexcept;

    [[nodiscard]] bool HasLost() const noexcept;

    void MarkAsLost() noexcept;

private:
    CardCollection hand_;
    const PlayerId id_;
    bool has_lost_;
};
