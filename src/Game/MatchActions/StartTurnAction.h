#pragma once

#include <Game/MatchActions/IMatchAction.h>

class StartTurnAction : public IMatchAction {
public:
    StartTurnAction();

    void Execute(Context* context, PlayerId owner, PlayerId target) const override;
};
