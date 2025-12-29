#include "NegativeResolveAction.h"

#include <Game/Entities/World.h>

NegativeResolveAction::NegativeResolveAction(const std::shared_ptr<BaseCard>& card)
: card_(card) {
}

void NegativeResolveAction::Execute(Context* context, PlayerId owner, PlayerId target) const {
    (void)context;
    (void)owner;
    (void)target;
    (void)card_;

    if (card_->IsComposite()) {
        const auto components = card_->GetComponents();
        for (const auto& component : components) {
            context->world->GetDiscardDeck().PlaceOnTop(component);
        }
    } else {
        context->world->GetDiscardDeck().PlaceOnTop(card_);
    }
}
