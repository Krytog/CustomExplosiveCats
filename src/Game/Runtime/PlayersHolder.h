#pragma once

#include <Game/Entities/Player.h>

#include <unordered_map>

class PlayersHolder {
public:
    PlayersHolder();

    PlayerId AddPlayer();

    [[nodiscard]] Player* GetPlayer(PlayerId id);

    [[nodiscard]] const Player* GetPlayer(PlayerId id) const;

    [[nodiscard]] size_t GetNextPlayerId(PlayerId id) const;

    [[nodiscard]] std::vector<PlayerId> GetAllPlayersIds() const;

    [[nodiscard]] PlayerId GetWhoseTurn() const;

    void SetWhoseTurn(PlayerId id);

private:
    std::unordered_map<PlayerId, Player> players_;
    std::vector<PlayerId> players_order_;
    PlayerId whose_turn_;
    PlayerId next_free_id_{1};
};
