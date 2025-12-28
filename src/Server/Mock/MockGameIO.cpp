#include "MockGameIO.h"

#include <iostream>
#include <format>

size_t MockGameIO::AskForPlace(PlayerId player) {
    size_t output;
    std::cin >> output;
    return output;
}

CardId MockGameIO::AskForCard(PlayerId player) {
    CardId id;
    std::cin >> id;
    return id;
}

std::vector<size_t> MockGameIO::AskForShuffle(PlayerId player) {
    std::vector<size_t> output;
    for (size_t i = 0; i < 5; ++i) {
        size_t temp;
        std::cin >> temp;
        output.push_back(temp);
    }
    return output;
}

void MockGameIO::SendCards(const std::vector<BaseCard*>& cards) {
    std::cout << "MockGameIO sends: ";
    for (const auto* card : cards) {
        std::cout << std::format("Card: id = {}, type = {}, subtype = {}", card->GetCardId(), card->GetTypeId(), card->GetSubtypeId()) << std::endl;
    }
}
