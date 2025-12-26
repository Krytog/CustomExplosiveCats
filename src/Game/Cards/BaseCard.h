#pragma once

#include <cstdint>

using CardTypeId = uint32_t;
using CardSubtypeId = uint32_t;

class BaseCard {
public:
    BaseCard(CardTypeId type_id, CardSubtypeId subtype_id) noexcept;

    virtual ~BaseCard();

    [[nodiscard]] CardTypeId GetTypeId() const noexcept;

    [[nodiscard]] CardSubtypeId GetSubtypeId() const noexcept;

    virtual void Play() const = 0;

protected:
    CardTypeId type_id_;
    CardSubtypeId subtype_id_;
};
