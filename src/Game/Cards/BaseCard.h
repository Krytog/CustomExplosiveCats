#pragma once

#include <cstdint>

using CardTypeId = uint32_t;
using CardSubtypeId = uint32_t;
using CardId = uint32_t;

class Player; // forward-declaration
class World; // forward-declaration

struct TurnContext {
    Player* active_player;
    World* world;
};

class BaseCard {
public:
    BaseCard(CardId id, CardTypeId type_id, CardSubtypeId subtype_id) noexcept;

    virtual ~BaseCard();

    [[nodiscard]] CardId GetCardId() const noexcept;

    [[nodiscard]] CardTypeId GetTypeId() const noexcept;

    [[nodiscard]] CardSubtypeId GetSubtypeId() const noexcept;

    virtual void Play(TurnContext* context) const = 0;

protected:
    CardId id_;
    CardTypeId type_id_;
    CardSubtypeId subtype_id_;
};
