#include "Player.h"

Player::Player(PlayerId id) : id_(id), has_lost_(false) {
}

CardCollection* Player::GetHand() noexcept {
    return &hand_;
}

const CardCollection* Player::GetHand() const noexcept {
    return &hand_;
}

PlayerId Player::GetId() const noexcept {
    return id_;
}

bool Player::HasLost() const noexcept {
    return has_lost_;
}

void Player::MarkAsLost() noexcept {
    has_lost_ = true;
}
