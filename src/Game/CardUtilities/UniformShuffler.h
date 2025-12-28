#pragma once

#include <Game/CardUtilities/IShuffler.h>

#include <Contrib/MOLS/src/Game/Fortuna/DistributionsProxy.h>

class UniformShuffler : public IShuffler {
public:
    explicit UniformShuffler(DistributionsProxy* dist_proxy);

    [[nodiscard]] std::vector<size_t> GetShuffle(size_t elements_count) override;
private:
    DistributionsProxy* const dist_proxy_;
};
