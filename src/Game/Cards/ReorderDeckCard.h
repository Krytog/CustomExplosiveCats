#pragma once

#include <Game/Cards/BaseCard.h>

class ReorderDeckCard : public BaseCard {
public:
    ReorderDeckCard(CardId id, CardSubtypeId subtype_id);

    void Play(const Context* context) const override;
};
