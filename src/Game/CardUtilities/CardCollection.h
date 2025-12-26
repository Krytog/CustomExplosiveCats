#pragma once

#include <Game/Cards/BaseCard.h>

#include <vector>
#include <memory>

class CardCollection {
public:
    CardCollection();

    [[nodiscard]] std::unique_ptr<BaseCard> TakeCard(size_t index);

    [[nodiscard]] BaseCard* GetCard(size_t index) const;

    void InsertCard(std::unique_ptr<BaseCard>&& card);

    void InsertCardAt(std::unique_ptr<BaseCard>&& card, size_t index);    

    void Reorder(const std::vector<size_t>& new_indices);

    void SwapCards(size_t lhs, size_t rhs);

    [[nodiscard]] size_t GetSize() const;

    [[nodiscard]] std::vector<BaseCard*> GetAllCards() const;

    [[nodiscard]] std::vector<BaseCard*> GetAllCardsOfType(CardTypeId type_id) const;

private:
    std::vector<std::unique_ptr<BaseCard>> cards_;
};
