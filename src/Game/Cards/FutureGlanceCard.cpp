#include "FutureGlanceCard.h"

#include <Game/Cards/CardTypesInfo.h>

FutureGlanceCard::FutureGlanceCard(CardSubtypeId subtype_id)
 : BaseCard(cards_constants::kFutureGlanceCardTypeId, subtype_id) {
}

void FutureGlanceCard::Play(TurnContext* context) const {

}
