#pragma once

#include <Game/CardUtilities/CardCollection.h>

class Deck {
public:
    Deck(std::vector<std::shared_ptr<BaseCard>>&& cards);

    std::shared_ptr<BaseCard> Draw();

    std::shared_ptr<BaseCard> TakeCardAt(size_t index);

    void PlaceOnTop(const std::shared_ptr<BaseCard>& card);

    void PlaceAtBottom(const std::shared_ptr<BaseCard>& card);

    void PlaceAt(const std::shared_ptr<BaseCard>& card, size_t index);

    void Shuffle(const std::vector<size_t>& new_indices);

    [[nodiscard]] size_t GetSize() const;

    [[nodiscard]] BaseCard* GetCardAt(size_t index) const;

    [[nodiscard]] BaseCard* GetTopCard(size_t index) const;

private:
    CardCollection cards_;
};
