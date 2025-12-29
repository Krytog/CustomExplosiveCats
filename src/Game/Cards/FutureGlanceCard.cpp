#include "FutureGlanceCard.h"

#include <Game/Cards/CardsConstants.h>
#include <Game/Entities/World.h>
#include <Game/Runtime/GameIO.h>

#include <vector>

FutureGlanceCard::FutureGlanceCard(CardId id, CardSubtypeId subtype_id)
 : BaseCard(id, cards_constants::kFutureGlanceCardTypeId, subtype_id) {
}

void FutureGlanceCard::Play(const Context* context) const {
    std::vector<BaseCard*> cards_to_show;
    constexpr size_t kCardsToShow = 3;
    cards_to_show.reserve(kCardsToShow);
    for (size_t i = 0; i < kCardsToShow; ++i) {
        auto* card = context->world->GetDeck().GetCardAt(i);
        cards_to_show.push_back(card);
    }
    context->io->SendCards(cards_to_show);
}
