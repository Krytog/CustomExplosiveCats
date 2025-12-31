#pragma once

#include <Game/Cards/BaseCard.h>

class AttackCard : public BaseCard {
public:
    AttackCard(CardId id, CardSubtypeId subtype_id);

    void Play(const Context* context) const override;
};
