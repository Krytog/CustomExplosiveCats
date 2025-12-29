#pragma once

#include <Game/Cards/BaseCard.h>

class ExplosiveCatCard : public BaseCard {
public:
    ExplosiveCatCard(CardId id, CardSubtypeId subtype_id);

    void Play(const Context* context) const override;
};
