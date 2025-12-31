#pragma once

#include <Game/Cards/BaseCard.h>
#include <Game/Entities/Player.h>

#include <memory>
#include <chrono>
#include <stack>
#include <unordered_set>

class MatchLog; // forward-declaration

class CardResolver {
public:
    struct Context {
        std::shared_ptr<BaseCard> card;
        BaseCard::Context card_context;
        std::chrono::time_point<std::chrono::steady_clock> ts;
    };

    CardResolver(MatchLog* log);

    void AddCardToResolve(const Context& context);

    void PositiveResolve();

    void NegativeResolve();

    [[nodiscard]] bool HasAnythingToResolve() const noexcept;

    [[nodiscard]] bool IsGivenPlayerWaitingForResolve(PlayerId player) const noexcept;

    [[nodiscard]] PlayerId GetWhoseResolveOnTop() const;

    void TryToResolve(std::chrono::time_point<std::chrono::steady_clock> ts);

private:
    std::stack<Context> resolve_stack_;
    MatchLog* const match_log_;
    std::unordered_set<PlayerId> waiting_players_;
};
