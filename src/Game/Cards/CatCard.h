#pragma once

#include <Game/Cards/BaseCard.h>

class CatCard : public BaseCard {
public:
    CatCard(CardId id, CardTypeId type_id);

    void Play(const Context* context) const override;
};
