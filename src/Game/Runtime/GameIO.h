#pragma once

#include <Game/Entities/Player.h>
#include <Game/Cards/BaseCard.h>

#include <Contrib/MOLS/src/Tools/Event/Event.h>

class GameIO {
public:
    using MessageEvent = Event<void(const std::string& message)>;

    virtual ~GameIO() = default;

    [[nodiscard]] virtual size_t AskForPlace(PlayerId player) = 0;

    [[nodiscard]] virtual CardId AskForCard(PlayerId player) = 0;

    [[nodiscard]] virtual std::vector<size_t> AskForShuffle(PlayerId player) = 0;

    virtual void SendCards(const std::vector<BaseCard*>& cards) = 0;
};
