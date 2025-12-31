#include "StartTurnAction.h"

#include <Game/Runtime/PlayersHolder.h>
#include <Utils/Exceptions.h>

StartTurnAction::StartTurnAction() = default;

void StartTurnAction::Execute(Context* context, PlayerId owner, PlayerId target) const {
    if (owner) {
        throw Exception("StartTurnAction::Execute: has owner");
    }

    if (context->players_holder->GetWhoseTurn() != target) {
        throw Exception("StartTurnAction::Execute: mismatch WhoseTurn = {} and target = {}",
                        context->players_holder->GetWhoseTurn(),
                        target);
    }

    if (!context->players_holder->GetTurnsForPlayer(context->players_holder->GetWhoseTurn())) {
        throw Exception("StartTurnAction::Execute: zero turn count for active player");
    }
}
