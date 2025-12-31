#include "AttackCard.h"

#include <Game/Cards/CardsConstants.h>
#include <Game/Runtime/PlayersHolder.h>

AttackCard::AttackCard(CardId id, CardSubtypeId subtype_id)
 : BaseCard(id, cards_constants::kAttackCardTypeId, subtype_id) {
}

void AttackCard::Play(const Context* context) const {
    constexpr size_t kAdditionalTurns = 2;
    const auto next_player = context->players->GetNextPlayerId(context->owner->GetId());
    const size_t turns_already_scheduled = context->players->GetTurnsForPlayer(next_player);
    context->players->SetTurnsForPlayer(next_player, turns_already_scheduled + kAdditionalTurns);

    context->players->SetWetherTurnCanEndWithoutDraw(true);
}
