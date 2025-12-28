#include "GameInitAction.h"

#include <Game/Cards/CardTypesInfo.h>
#include <Game/Cards/FutureGlanceCard.h>
#include <Game/CardUtilities/IShuffler.h>
#include <Game/CardUtilities/UniformShuffler.h>
#include <Game/Entities/World.h>

namespace {

void FulfillDeckWithoutSpecialCards(Deck* deck) {
    for (size_t i = 0; i < cards_constants::kFutureGlanceCardCount; ++i) {
        deck->PlaceAtBottom(std::make_unique<FutureGlanceCard>(i));
    }
}

std::unique_ptr<Deck> CreateDeckWithoutSpecialCards(IShuffler* shuffler) {
    auto deck = std::make_unique<Deck>(std::vector<std::unique_ptr<BaseCard>>{});
    FulfillDeckWithoutSpecialCards(deck.get());
    return deck;
}

void InitializeWorld(World* world, DistributionsProxy* dist_proxy) {
    UniformShuffler shuffler(dist_proxy);
    auto deck = CreateDeckWithoutSpecialCards(&shuffler);
    world->GetDeck() = *deck;
}

}

