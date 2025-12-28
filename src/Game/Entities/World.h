#pragma once

#include <Game/CardUtilities/Deck.h>

class World {
public:
    World();

    [[nodiscard]] Deck& GetDeck() noexcept;

    [[nodiscard]] const Deck& GetDeck() const noexcept;

    [[nodiscard]] Deck& GetDiscardDeck() noexcept;

    [[nodiscard]] const Deck& GetDiscardDeck() const noexcept;

    [[nodiscard]] size_t GetTurnNumber() const noexcept;

    void IncrementTurnCount() noexcept;

private:
    Deck deck_;
    Deck discard_deck_;
    size_t turn_number_{0};
};
