#include "CardResolver.h"

#include <Game/MatchActions/PositiveResolveAction.h>
#include <Game/MatchActions/NegativeResolveAction.h>
#include <Game/Runtime/MatchLog.h>
#include <Utils/Exceptions.h>

CardResolver::CardResolver(MatchLog* match_log)
 : match_log_(match_log) {
}

void CardResolver::AddCardToResolve(const Context& context) {
    resolve_stack_.push(context);
}

void CardResolver::PositiveResolve() {
    if (resolve_stack_.empty()) {
        throw Exception("CardResolver::PositiveResolve: nothing to resolve");
    }

    auto context = std::move(resolve_stack_.top());
    resolve_stack_.pop();
    match_log_->AddEntry(MatchLog::LogEntry{
        .action = std::make_unique<PositiveResolveAction>(context.card, context.card_context),
        .owner = 0,
        .target = 0,
    });
}

void CardResolver::NegativeResolve() {
    if (resolve_stack_.empty()) {
        throw Exception("CardResolver::NegativeResolve: nothing to resolve");
    }

    auto context = std::move(resolve_stack_.top());
    resolve_stack_.pop();
    match_log_->AddEntry(MatchLog::LogEntry{
        .action = std::make_unique<NegativeResolveAction>(context.card),
        .owner = 0,
        .target = 0,
    });
}

bool CardResolver::HasAnythingToResolve() const noexcept {
    return !resolve_stack_.empty();
}

void CardResolver::TryToResolve(std::chrono::time_point<std::chrono::steady_clock> ts) {
    if (resolve_stack_.empty()) {
        return;
    }
    if (ts < resolve_stack_.top().ts) {
        return;
    }

    PositiveResolve();
}

bool CardResolver::IsGivenPlayerWaitingForResolve(PlayerId player) const noexcept {
    return waiting_players_.contains(player);
}

PlayerId CardResolver::GetWhoseResolveOnTop() const {
    if (resolve_stack_.empty()) {
        return 0;
    }

    const auto* player = resolve_stack_.top().card_context.owner;
    if (!player) {
        throw Exception("CardResolver::GetWhoseResolveOnTop: player = nullptr");
    }

    return player->GetId();
}
