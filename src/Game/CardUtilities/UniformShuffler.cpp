#include "UniformShuffler.h"

UniformShuffler::UniformShuffler(DistributionsProxy* dist_proxy)
 : dist_proxy_(dist_proxy) {
}

std::vector<size_t> UniformShuffler::GetShuffle(size_t elements_count) {
    std::vector<size_t> output;
    output.reserve(elements_count);
    for (size_t i = 0; i < elements_count; ++i) {
        output.push_back(i);
    }
    for (size_t i = 0; i < elements_count; ++i) {
        std::swap(output[i], output[dist_proxy_->GetRandomValueFromUniformIntDistribution(0, elements_count)]);
    }
    return output;
}
