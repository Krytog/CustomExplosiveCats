#pragma once

#include <Game/Cards/BaseCard.h>

class DefuseCard : public BaseCard {
public:
    DefuseCard(CardId id, CardSubtypeId subtype_id);

    void Play(const Context* context) const override;
};
