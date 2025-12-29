#pragma once

#include <cstdint>
#include <vector>
#include <memory>

using CardTypeId = uint32_t;
using CardSubtypeId = uint32_t;
using CardId = uint32_t;

class Player; // forward-declaration
class World; // forward-declaration
class PlayersHolder; // forward-declaration
class GameIO; // forward-declaration
class Fortuna; // forward-declaration
class CardResolver; // forward-declaration

class BaseCard {
public:
    struct Context {
        Player* owner;
        Player* target;
        World* world;
        PlayersHolder* players;
        CardResolver* card_resolver;
        GameIO* io;
        Fortuna* fortuna;
    };

    BaseCard(CardId id, CardTypeId type_id, CardSubtypeId subtype_id) noexcept;

    virtual ~BaseCard();

    [[nodiscard]] CardId GetCardId() const noexcept;

    [[nodiscard]] CardTypeId GetTypeId() const noexcept;

    [[nodiscard]] CardSubtypeId GetSubtypeId() const noexcept;

    virtual void Play(const Context* context) const = 0;

    [[nodiscard]] virtual bool IsComposite() const noexcept;

    [[nodiscard]] virtual std::vector<std::shared_ptr<BaseCard>> GetComponents() const;

protected:
    CardId id_;
    CardTypeId type_id_;
    CardSubtypeId subtype_id_;
};
