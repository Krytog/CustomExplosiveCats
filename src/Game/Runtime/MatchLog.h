#pragma once

#include <Game/Entities/Player.h>
#include <Game/Cards/BaseCard.h>

#include <memory>
#include <vector>

class IMatchAction; // forward-declaration

class MatchLog {
public:
    struct LogEntry {
        std::unique_ptr<IMatchAction> action;
        PlayerId owner;
        PlayerId target;
    };

    MatchLog();

    void AddEntry(LogEntry&& log_entry);

    [[nodiscard]] size_t GetSize() const noexcept;

    [[nodiscard]] const LogEntry& GetLogEntry(size_t index) const; 

private:
    std::vector<LogEntry> entries_;
};
