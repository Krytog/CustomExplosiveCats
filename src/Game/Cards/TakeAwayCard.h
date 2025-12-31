#pragma once

#include <Game/Cards/BaseCard.h>

class TakeAwayCard : public BaseCard {
public:
    TakeAwayCard(CardId id, CardSubtypeId subtype_id);

    void Play(const Context* context) const override;
};
