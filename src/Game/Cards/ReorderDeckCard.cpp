#include "ReorderDeckCard.h"

#include <Game/Cards/CardsConstants.h>
#include <Game/Runtime/GameIO.h>
#include <Game/Entities/World.h>
#include <Utils/Exceptions.h>

ReorderDeckCard::ReorderDeckCard(CardId id, CardSubtypeId subtype_id)
 : BaseCard(id, cards_constants::kReorderDeckCardTypeId, subtype_id) {
}

void ReorderDeckCard::Play(const Context* context) const {
    while (true) {
        const auto reorder = context->io->AskForShuffle(context->owner->GetId());
        if (reorder.size() == context->world->GetDeck().GetSize()) {
            context->world->GetDeck().Shuffle(reorder);
            context->io->BroadcastReorder(reorder, std::nullopt);
            break;
        }
    }
}
