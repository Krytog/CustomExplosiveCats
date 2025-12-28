#pragma once

#include <vector>

class IShuffler {
public:
    virtual ~IShuffler() = default;

    [[nodiscard]] virtual std::vector<size_t> GetShuffle(size_t elements_count) = 0;
};
