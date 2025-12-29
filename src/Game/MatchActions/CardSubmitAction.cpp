#include "CardSubmitAction.h"

#include <Game/Cards/BaseCard.h>
#include <Game/Runtime/CardResolver.h>
#include <Game/Runtime/PlayersHolder.h>

#include <chrono>

CardSubmitAction::CardSubmitAction(const std::shared_ptr<BaseCard>& card)
 : card_(card) {
}

void CardSubmitAction::Execute(Context* context, PlayerId owner, PlayerId target) const {
    const auto ts = std::chrono::steady_clock::now();
    Player* submiter = context->players_holder->GetPlayer(owner);
    CardResolver::Context resolver_context{
        .card = card_,
        .card_context = BaseCard::Context{
            .owner = submiter,
            .target = context->players_holder->GetPlayer(target),
            .world = context->world,
            .players = context->players_holder,
            .card_resolver = context->card_resolver,
            .io = context->io,
            .fortuna = context->fortuna,
        },
        .ts = ts,
    };

    if (card_->IsComposite()) {
        const auto components = card_->GetComponents();
        for (const auto& component : components) {
            const auto card_index = submiter->GetHand()->GetIndexById(component->GetCardId());
            submiter->GetHand()->TakeCard(card_index);
        }
    } else {
        const auto card_index = submiter->GetHand()->GetIndexById(card_->GetCardId());
        submiter->GetHand()->TakeCard(card_index);
    }

    context->card_resolver->AddCardToResolve(resolver_context);
}
