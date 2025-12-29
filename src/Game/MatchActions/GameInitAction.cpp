#include "GameInitAction.h"

#include <Game/Cards/CardsConstants.h>
#include <Game/Cards/FutureGlanceCard.h>
#include <Game/CardUtilities/IShuffler.h>
#include <Game/CardUtilities/UniformShuffler.h>
#include <Game/Entities/World.h>
#include <Game/Runtime/PlayersHolder.h>

#include <Contrib/MOLS/src/Game/Fortuna/Fortuna.h>

namespace {

void FulfillDeckWithoutSpecialCards(Deck* deck) {
    for (size_t i = 0; i < cards_constants::kFutureGlanceCardCount; ++i) {
        deck->PlaceAtBottom(std::make_shared<FutureGlanceCard>(i));
    }
}

void FulfillDeckWithSpecialCards(Deck* deck) {
    (void)deck;
}

void ShuffleDeck(Deck* deck, DistributionsProxy* dist_proxy) {
    UniformShuffler shuffler(dist_proxy);
    const auto shuffled_order = shuffler.GetShuffle(deck->GetSize());
    deck->Shuffle(shuffled_order);
}

void DealCardsToPlayers(PlayersHolder* players_holder, Deck* deck, DistributionsProxy* dist_proxy) {
    const auto players = players_holder->GetAllPlayersIds();
    for (size_t i = 0; i < cards_constants::kCardsToDealCount; ++i) {
        for (const auto player : players) {
            const size_t random_index = dist_proxy->GetRandomValueFromUniformIntDistribution(0, deck->GetSize() - 1);
            auto card = deck->TakeCardAt(random_index);
            players_holder->GetPlayer(player)->GetHand()->InsertCard(std::move(card));
        }
    }
}

void SetWhoseTurn(PlayersHolder* players_holder, DistributionsProxy* dist_proxy) {
    const auto players = players_holder->GetAllPlayersIds();
    const auto random_index = dist_proxy->GetRandomValueFromUniformIntDistribution(0, players.size() - 1);
    const auto first_to_make_turn = players[random_index];
    players_holder->SetWhoseTurn(first_to_make_turn);
}

}

void GameInitAction::Execute(Context* context, PlayerId owner, PlayerId target) const {
    (void)owner;
    (void)target;

    FulfillDeckWithoutSpecialCards(&context->world->GetDeck());
    DealCardsToPlayers(context->players_holder, &context->world->GetDeck(), context->fortuna->GetDistributionsProxy());
    FulfillDeckWithSpecialCards(&context->world->GetDeck());
    ShuffleDeck(&context->world->GetDeck(), context->fortuna->GetDistributionsProxy());
    SetWhoseTurn(context->players_holder, context->fortuna->GetDistributionsProxy());
}
