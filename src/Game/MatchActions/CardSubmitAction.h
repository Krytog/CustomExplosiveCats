#pragma once

#include <Game/MatchActions/IMatchAction.h>

#include <memory>

class BaseCard; // forward-declaration

class CardSubmitAction : IMatchAction {
public:
    CardSubmitAction(const std::shared_ptr<BaseCard>& card);

    void Execute(Context* context, PlayerId owner, PlayerId target) const override;

private:
    std::shared_ptr<BaseCard> card_;
};
