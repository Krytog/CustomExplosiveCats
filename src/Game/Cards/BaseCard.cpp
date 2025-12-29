#include "BaseCard.h"

BaseCard::BaseCard(CardId id, CardTypeId type_id, CardSubtypeId subtype_id) noexcept
 : id_(id), type_id_(type_id), subtype_id_(subtype_id) {}

BaseCard::~BaseCard() = default;

CardId BaseCard::GetCardId() const noexcept {
    return id_;
}

CardTypeId BaseCard::GetTypeId() const noexcept {
    return type_id_;
}

CardSubtypeId BaseCard::GetSubtypeId() const noexcept {
    return subtype_id_;
}

bool BaseCard::IsComposite() const noexcept {
    return false;
}

std::vector<std::shared_ptr<BaseCard>> BaseCard::GetComponents() const {
    return {};
}
