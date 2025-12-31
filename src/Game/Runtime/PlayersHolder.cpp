#include "PlayersHolder.h"

#include <Utils/Exceptions.h>

#include <algorithm>

PlayersHolder::PlayersHolder() {}

PlayerId PlayersHolder::AddPlayer() {
    const PlayerId id = next_free_id_;
    ++next_free_id_;

    players_.emplace(id, Player(id));
    players_order_.push_back(id);
    turns_to_make_[id] = 0;

    return id;
}

Player* PlayersHolder::GetPlayer(PlayerId id) {
    if (!id) {
        return nullptr; // it's a special case for inner use
    }

    if (!players_.contains(id)) {
        throw Exception("PlayersHolder::GetPlayer: no player with id = {}", id);
    }

    return &players_.at(id);
}

const Player* PlayersHolder::GetPlayer(PlayerId id) const {
    if (!id) {
        return nullptr; // it's a special case for inner use
    }

    if (!players_.contains(id)) {
        throw Exception("PlayersHolder::GetPlayer: no player with id = {}", id);
    }

    return &players_.at(id);
}

PlayerId PlayersHolder::GetNextPlayerId(PlayerId id) const {
    const auto player_it = std::find(players_order_.begin(), players_order_.end(), id);
    if (player_it == players_order_.end()) {
        throw Exception("PlayersHolder::GetNextPlayerId: no player with id = {}", id);
    }

    if (player_it + 1 == players_order_.end()) {
        return players_order_[0];
    }
    return *(player_it + 1);
}

std::vector<PlayerId> PlayersHolder::GetAllPlayersIds() const {
    return players_order_;
}

PlayerId PlayersHolder::GetWhoseTurn() const {
    return whose_turn_;
}

void PlayersHolder::SetWhoseTurn(PlayerId id) {
    whose_turn_ = id;
}

size_t PlayersHolder::GetTurnsForPlayer(PlayerId id) const {
    if (!turns_to_make_.contains(id)) {
        throw Exception("PlayersHolder::GetTurnsForPlayer: no player with id = {}", id);
    }

    return turns_to_make_.at(id);
}

void PlayersHolder::SetTurnsForPlayer(PlayerId id, size_t turns) {
    if (!turns_to_make_.contains(id)) {
        throw Exception("PlayersHolder::SetTurnsForPlayer: no player with id = {}", id);
    }

    turns_to_make_[id] = turns;
}

std::vector<PlayerId> PlayersHolder::GetNotLostPlayers() const {
    std::vector<PlayerId> output;
    for (const auto& [id, player] : players_) {
        if (!player.HasLost()) {
            output.push_back(player.GetId());
        }
    }
    return output;
}

void PlayersHolder::HandOver() {
    const auto next_player = GetNextPlayerId(whose_turn_);
    if (!turns_to_make_[next_player]) {
        turns_to_make_[next_player] = 1;
    }
    whose_turn_ = next_player;
}

bool PlayersHolder::CanTurnEndWithoutDraw() const noexcept {
    return no_draw_this_turn_;
}

void PlayersHolder::SetWetherTurnCanEndWithoutDraw(bool no_draw_this_turn) noexcept {
    no_draw_this_turn_ = no_draw_this_turn;
}
