#include "Deck.h"

#include <Utils/Exceptions.h>

Deck::Deck(std::vector<std::shared_ptr<BaseCard>>&& cards) {
    for (auto&& card : cards) {
        cards_.InsertCard(std::move(card));
    }
}

std::shared_ptr<BaseCard> Deck::Draw() {
    if (!cards_.GetSize()) {
        throw Exception("Deck::Draw: draw from empty deck");
    }

    return cards_.TakeCard(0);
}

std::shared_ptr<BaseCard> Deck::TakeCardAt(size_t index) {
    return cards_.TakeCard(index);
}

void Deck::PlaceOnTop(const std::shared_ptr<BaseCard>& card) {
    cards_.InsertCardAt(std::move(card), 0);
}

void Deck::PlaceAtBottom(const std::shared_ptr<BaseCard>& card) {
    cards_.InsertCard(std::move(card));
}

void Deck::PlaceAt(const std::shared_ptr<BaseCard>& card, size_t index) {
    cards_.InsertCardAt(card, index);
}

void Deck::Shuffle(const std::vector<size_t>& new_indices) {
    cards_.Reorder(new_indices);
}

size_t Deck::GetSize() const {
    return cards_.GetSize();
}

BaseCard* Deck::GetCardAt(size_t index) const {
    return cards_.GetCard(index);
}

BaseCard* Deck::GetTopCard(size_t index) const {
    return cards_.GetCard(0);
}
