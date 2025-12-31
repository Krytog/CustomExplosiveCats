#pragma once

#include <Game/MatchActions/IMatchAction.h>

class EndTurnAction : public IMatchAction {
public:
    EndTurnAction();

    void Execute(Context* context, PlayerId owner, PlayerId target) const override;
};
