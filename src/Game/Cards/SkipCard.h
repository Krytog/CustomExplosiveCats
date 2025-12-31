#pragma once

#include <Game/Cards/BaseCard.h>

class SkipCard : public BaseCard {
public:
    SkipCard(CardId id, CardSubtypeId subtype_id);

    void Play(const Context* context) const override;
};
