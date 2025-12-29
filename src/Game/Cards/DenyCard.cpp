#include "DenyCard.h"

#include <Game/Cards/CardsConstants.h>
#include <Game/Runtime/CardResolver.h>
#include <Utils/Exceptions.h>

DenyCard::DenyCard(CardId id, CardSubtypeId subtype_id)
 : BaseCard(id, cards_constants::kDenyCardTypeId, subtype_id) {
}

void DenyCard::Play(const Context* context) const {
    auto* resolver = context->card_resolver;
    if (!resolver->HasAnythingToResolve()) {
        throw Exception("DenyCard::Play: has nothing to resolve");
    }
    resolver->NegativeResolve();
}
