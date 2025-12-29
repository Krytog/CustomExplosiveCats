#pragma once

#include <Game/MatchActions/IMatchAction.h>
#include <Game/Runtime/CardResolver.h>

class PositiveResolveAction : public IMatchAction {
public:
    PositiveResolveAction(const std::shared_ptr<BaseCard>& card, const BaseCard::Context& card_context);

    void Execute(Context* context, PlayerId owner, PlayerId target) const override;

private:
    std::shared_ptr<BaseCard> card_;
    BaseCard::Context card_context_;
};
