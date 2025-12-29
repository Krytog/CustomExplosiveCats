#pragma once

#include <Game/Cards/BaseCard.h>

class DenyCard : public BaseCard {
public:
    DenyCard(CardId id, CardSubtypeId subtype_id);

    void Play(const Context* context) const override;
};
