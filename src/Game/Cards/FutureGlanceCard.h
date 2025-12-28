#pragma once

#include <Game/Cards/BaseCard.h>

class FutureGlanceCard : public BaseCard {
public:
    FutureGlanceCard(CardSubtypeId subtype_id);

    void Play(TurnContext* context) const override;
};
