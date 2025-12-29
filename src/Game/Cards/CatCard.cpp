#include "CatCard.h"

#include <Game/Cards/CardsConstants.h>
#include <Utils/Exceptions.h>

CatCard::CatCard(CardId id, CardId card_id)
 : BaseCard(id, card_id, 0) {
}

void CatCard::Play(const Context* context) const {
    throw Exception("CatCard::Play: tried to play CatCard");
}
