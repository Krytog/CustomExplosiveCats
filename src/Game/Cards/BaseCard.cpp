#include "BaseCard.h"

BaseCard::BaseCard(CardTypeId type_id, CardSubtypeId subtype_id) noexcept
 : type_id_(type_id), subtype_id_(subtype_id) {}

BaseCard::~BaseCard() = default;

CardTypeId BaseCard::GetTypeId() const noexcept {
    return type_id_;
}

CardSubtypeId BaseCard::GetSubtypeId() const noexcept {
    return subtype_id_;
}
