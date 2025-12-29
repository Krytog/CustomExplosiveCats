#pragma once

#include <Game/Cards/BaseCard.h>

#include <memory>
#include <chrono>
#include <stack>

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

private:
    std::stack<Context> resolve_stack_;
};
