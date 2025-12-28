#include "World.h"

World::World() : deck_({}), discard_deck_({}) {
}

Deck& World::GetDeck() noexcept {
    return deck_;
}

const Deck& World::GetDeck() const noexcept {
    return deck_;
}

Deck& World::GetDiscardDeck() noexcept {
    return discard_deck_;
}

const Deck& World::GetDiscardDeck() const noexcept {
    return discard_deck_;
}

size_t World::GetTurnNumber() const noexcept {
    return turn_number_;
}

void World::IncrementTurnCount() noexcept {
    ++turn_number_;
}
