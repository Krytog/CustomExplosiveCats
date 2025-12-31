#pragma once

#include <Game/Entities/Player.h>
#include <Game/Cards/BaseCard.h>

#include <optional>
#include <string>

class GameIO {
public:
    struct SubmitIntention {
        std::optional<CardId> card;
        PlayerId player;
        PlayerId target;
    };

    enum class SendReason {
        CardSumbitted,
        CardResolved,
        CardAddedToHand,
        CardTaken,
        CardsReordered,
        CardsShown,
    };

    enum class DrawnType {
        NormalDraw,
        ExplosiveCatDraw,
    };

    virtual ~GameIO() = default;

    [[nodiscard]] virtual std::optional<SubmitIntention> FetchSubmitIntention() = 0;

    [[nodiscard]] virtual size_t AskForPlace(PlayerId player) = 0;

    [[nodiscard]] virtual CardId AskForCard(PlayerId player) = 0;

    [[nodiscard]] virtual std::vector<size_t> AskForShuffle(PlayerId player) = 0;

    virtual void SendCards(PlayerId player, const std::vector<BaseCard*>& cards, SendReason reason) = 0;

    virtual void BroadcastCards(const std::vector<BaseCard*>& cards, SendReason reason) = 0;

    virtual void BroadcastReorder(const std::vector<size_t>& new_order, std::optional<PlayerId> target) = 0;

    virtual void BroadcastDraw(DrawnType type) = 0;

    virtual void SendInfo(PlayerId player, const std::string& info) = 0;
};
