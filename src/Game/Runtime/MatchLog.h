#pragma once

#include <Game/Entities/Player.h>
#include <Game/Cards/BaseCard.h>

#include <memory>
#include <vector>
#include <stack>

class IMatchAction; // forward-declaration

class MatchLog {
public:
    struct LogEntry {
        std::unique_ptr<IMatchAction> action;
        PlayerId target;
        PlayerId owner;
    };

    MatchLog();

    void AddEntry(LogEntry&& log_entry);

    [[nodiscard]] size_t GetSize() const noexcept;

    [[nodiscard]] const LogEntry& GetLogEntry(size_t index) const; 

private:
    std::vector<LogEntry> entries_;
    std::stack<std::shared_ptr<BaseCard>> resolve_stack_;
};
