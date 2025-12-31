#pragma once

#include <Game/Entities/Player.h>

#include <unordered_map>

class PlayersHolder {
public:
    PlayersHolder();

    PlayerId AddPlayer();

    [[nodiscard]] Player* GetPlayer(PlayerId id);

    [[nodiscard]] const Player* GetPlayer(PlayerId id) const;

    [[nodiscard]] PlayerId GetNextPlayerId(PlayerId id) const;

    [[nodiscard]] std::vector<PlayerId> GetAllPlayersIds() const;

    [[nodiscard]] PlayerId GetWhoseTurn() const;

    void SetWhoseTurn(PlayerId id);

    [[nodiscard]] size_t GetTurnsForPlayer(PlayerId id) const;

    void SetTurnsForPlayer(PlayerId id, size_t turns);

    [[nodiscard]] std::vector<PlayerId> GetNotLostPlayers() const;

    void HandOver();

    [[nodiscard]] bool CanTurnEndWithoutDraw() const noexcept;

    void SetWetherTurnCanEndWithoutDraw(bool no_draw_this_turn) noexcept;

private:
    std::unordered_map<PlayerId, Player> players_;
    std::unordered_map<PlayerId, size_t> turns_to_make_;
    std::vector<PlayerId> players_order_;
    PlayerId whose_turn_;
    bool no_draw_this_turn_{false};
    PlayerId next_free_id_{1};
};
