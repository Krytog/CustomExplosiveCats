#include "ExplosiveCatCard.h"

#include <Game/Cards/CardsConstants.h>
#include <Utils/Exceptions.h>

ExplosiveCatCard::ExplosiveCatCard(CardId id, CardSubtypeId subtype_id)
 : BaseCard(id, cards_constants::kExplosiveCatCardTypeId, subtype_id) {
}

void ExplosiveCatCard::Play(const Context* context) const {
    throw Exception("ExplosiveCatCard::Play: tried to play ExplosiveCatCard");
}
