#include "PositiveResolveAction.h"

#include <Game/Entities/World.h>

PositiveResolveAction::PositiveResolveAction(const std::shared_ptr<BaseCard>& card, const BaseCard::Context& card_context)
: card_(card), card_context_(card_context) {
}

void PositiveResolveAction::Execute(Context* context, PlayerId owner, PlayerId target) const {
    (void)owner;
    (void)target;

    card_->Play(&card_context_);
    if (card_->IsComposite()) {
        const auto components = card_->GetComponents();
        for (const auto& component : components) {
            context->world->GetDiscardDeck().PlaceOnTop(component);
        }
    } else {
        context->world->GetDiscardDeck().PlaceOnTop(card_);
    }
}
