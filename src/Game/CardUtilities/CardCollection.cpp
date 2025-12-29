#include "CardCollection.h"

#include <Utils/Exceptions.h>

#include <unordered_set>

CardCollection::CardCollection() = default;

std::shared_ptr<BaseCard> CardCollection::TakeCard(size_t index) {
    if (index >= cards_.size()) {
        throw Exception("CardCollection:TakeCard, index = {}, size = {}", index, cards_.size());
    }

    auto output = std::move(cards_[index]);
    cards_.erase(cards_.begin() + index);
    return output;
}

BaseCard* CardCollection::GetCard(size_t index) const {
    if (index >= cards_.size()) {
        throw Exception("CardCollection:GetCard, index = {}, size = {}", index, cards_.size());
    }

    return cards_[index].get();
}

void CardCollection::InsertCard(const std::shared_ptr<BaseCard>& card) {
    cards_.push_back(std::move(card));
}

void CardCollection::InsertCardAt(const std::shared_ptr<BaseCard>& card, size_t index) {
    cards_.insert(cards_.begin() + index, std::move(card));
}

void CardCollection::Reorder(const std::vector<size_t>& new_indices) {
    if (new_indices.size() != cards_.size()) {
        throw Exception("CardCollection::Reorder: size mismatch, indices size = {}, cards size = {}", new_indices.size(), cards_.size());
    }

    std::unordered_set<size_t> used_indices;
    std::vector<std::shared_ptr<BaseCard>> temp(cards_.size());
    for (size_t i = 0; i < new_indices.size(); ++i) {
        const size_t index = new_indices[i];

        if (used_indices.contains(index)) {
            throw Exception("CardCollection::Reorder: index = {} used twice", index);
        }
        used_indices.insert(index);

        temp[index] = std::move(cards_[i]);
    }
    cards_ = std::move(temp);
}

void CardCollection::SwapCards(size_t lhs, size_t rhs) {
    std::swap(cards_[lhs], cards_[rhs]);
}

size_t CardCollection::GetSize() const {
    return cards_.size();
}

std::vector<BaseCard*> CardCollection::GetAllCards() const {
    std::vector<BaseCard*> output;
    output.reserve(cards_.size());
    for (const auto& card : cards_) {
        output.push_back(card.get());
    }
    return output;
}

std::vector<BaseCard*> CardCollection::GetAllCardsOfType(CardTypeId type_id) const {
    std::vector<BaseCard*> output;
    for (const auto& card : cards_) {
        if (card->GetTypeId() == type_id) {
            output.push_back(card.get());
        }
    }
    return output;
}

size_t CardCollection::GetIndexById(CardId id) const {
    for (size_t i = 0; i < cards_.size(); ++i) {
        if (cards_[i]->GetCardId() == id) {
            return i;
        }
    }

    throw Exception("CardCollection::GetIndexById: no card with id = {}", id);
}

bool CardCollection::HasGivenId(CardId id) const {
    for (size_t i = 0; i < cards_.size(); ++i) {
        if (cards_[i]->GetCardId() == id) {
            return true;
        }
    }
    return false;
}
