#include "DefuseCard.h"

#include <Game/Cards/CardsConstants.h>
#include <Utils/Exceptions.h>

DefuseCard::DefuseCard(CardId id, CardSubtypeId subtype_id)
 : BaseCard(id, cards_constants::kDefuseCardTypeId, subtype_id) {
}

void DefuseCard::Play(const Context* context) const {
    throw Exception("DefuseCard::Play: tried to play DefuseCard");
}
