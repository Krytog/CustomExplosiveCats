#include "MatchLog.h"

MatchLog::MatchLog() = default;

void MatchLog::AddEntry(LogEntry&& log_entry) {
    entries_.push_back(std::move(log_entry));
}

size_t MatchLog::GetSize() const noexcept {
    return entries_.size();
}

const MatchLog::LogEntry& MatchLog::GetLogEntry(size_t index) const {
    return entries_[index];
}
