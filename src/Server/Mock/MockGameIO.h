#pragma once

#include <Game/Runtime/GameIO.h>

class MockGameIO : public GameIO {
public:
    using MessageEvent = Event<void(const std::string& message)>;

    MockGameIO() = default;

    [[nodiscard]] size_t AskForPlace(PlayerId player) override;

    [[nodiscard]] CardId AskForCard(PlayerId player) override;

    [[nodiscard]] std::vector<size_t> AskForShuffle(PlayerId player) override;

    void SendCards(const std::vector<BaseCard*>& cards) override;
};
