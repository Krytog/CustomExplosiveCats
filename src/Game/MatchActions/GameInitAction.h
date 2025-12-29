#pragma once

#include <Game/MatchActions/IMatchAction.h>

class GameInitAction : public IMatchAction {
public:
    void Execute(Context* context, PlayerId owner, PlayerId target) const override;
};
