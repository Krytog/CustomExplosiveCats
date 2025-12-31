#include "SkipCard.h"

#include <Game/Cards/CardsConstants.h>
#include <Game/Runtime/PlayersHolder.h>

SkipCard::SkipCard(CardId id, CardSubtypeId subtype_id)
 : BaseCard(id, cards_constants::kSkipCardTypeId, subtype_id) {
}

void SkipCard::Play(const Context* context) const {
    context->players->SetWetherTurnCanEndWithoutDraw(true);
}
