#pragma once

#include <Game/CardUtilities/CardCollection.h>

class Deck {
public:
    Deck(std::vector<std::unique_ptr<BaseCard>>&& cards);

    std::unique_ptr<BaseCard> Draw();

    std::unique_ptr<BaseCard> TakeCardAt(size_t index);

    void PlaceOnTop(std::unique_ptr<BaseCard>&& card);

    void PlaceAtBottom(std::unique_ptr<BaseCard>&& card);

    void Shuffle(const std::vector<size_t>& new_indices);

    [[nodiscard]] size_t GetSize() const;

    [[nodiscard]] BaseCard* GetCardAt(size_t index) const;

    [[nodiscard]] BaseCard* GetTopCard(size_t index) const;

private:
    CardCollection cards_;
};
