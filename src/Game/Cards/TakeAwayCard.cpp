#include "TakeAwayCard.h"

#include <Game/Cards/CardsConstants.h>
#include <Game/Runtime/GameIO.h>
#include <Game/Runtime/PlayersHolder.h>
#include <Utils/Exceptions.h>

TakeAwayCard::TakeAwayCard(CardId id, CardSubtypeId subtype_id)
 : BaseCard(id, cards_constants::kTakeAwayCardTypeId, subtype_id) {
}

void TakeAwayCard::Play(const Context* context) const {
    if (!context->target) {
        throw Exception("TakeAwayCard::Play: empty target");
    }

    std::shared_ptr<BaseCard> card_to_take;
    while (true) {
        const auto card_id = context->io->AskForCard(context->target->GetId());
        if (context->target->GetHand()->HasGivenId(card_id)) {
            const size_t index = context->target->GetHand()->GetIndexById(card_id);
            card_to_take = context->target->GetHand()->TakeCard(index);
            context->io->SendCards(context->target->GetId(), {card_to_take.get()}, GameIO::SendReason::CardTaken);
            break;
        }
    }

    context->owner->GetHand()->InsertCard(card_to_take);
    context->io->SendCards(context->owner->GetId(), {card_to_take.get()}, GameIO::SendReason::CardAddedToHand);
}
