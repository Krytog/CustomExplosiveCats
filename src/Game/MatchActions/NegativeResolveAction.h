#pragma once

#include <Game/MatchActions/IMatchAction.h>
#include <Game/Runtime/CardResolver.h>

class NegativeResolveAction : public IMatchAction {
public:
    NegativeResolveAction(const std::shared_ptr<BaseCard>& card);

    void Execute(Context* context, PlayerId owner, PlayerId target) const override;

private:
    std::shared_ptr<BaseCard> card_;
};
