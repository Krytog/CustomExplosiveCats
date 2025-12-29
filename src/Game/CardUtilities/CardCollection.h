#pragma once

#include <Game/Cards/BaseCard.h>

#include <vector>
#include <memory>

class CardCollection {
public:
    CardCollection();

    std::shared_ptr<BaseCard> TakeCard(size_t index);

    [[nodiscard]] BaseCard* GetCard(size_t index) const;

    void InsertCard(const std::shared_ptr<BaseCard>& card);

    void InsertCardAt(const std::shared_ptr<BaseCard>& card, size_t index);    

    void Reorder(const std::vector<size_t>& new_indices);

    void SwapCards(size_t lhs, size_t rhs);

    [[nodiscard]] size_t GetSize() const;

    [[nodiscard]] size_t GetIndexById(CardId id) const;

    [[nodiscard]] bool HasGivenId(CardId id) const;

    [[nodiscard]] std::vector<BaseCard*> GetAllCards() const;

    [[nodiscard]] std::vector<BaseCard*> GetAllCardsOfType(CardTypeId type_id) const;

private:
    std::vector<std::shared_ptr<BaseCard>> cards_;
};
