#pragma once

#include <Game/MatchActions/IMatchAction.h>

class GameInitAction : public IMatchAction {
public:
    void Execute(Context* context) const override;
};
