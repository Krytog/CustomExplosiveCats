#pragma once

#include <Game/Cards/BaseCard.h>

#include <cstddef>

namespace cards_constants {

static const CardTypeId kBaseCardTypeId = 0;
static const CardTypeId kExplosiveCatCardTypeId = 1;
static const CardTypeId kDefuseCardTypeId = 2;
static const CardTypeId kDenyCardTypeId = 3;
static const CardTypeId kAttackCardTypeId = 4;
static const CardTypeId kSkipCardTypeId = 5;
static const CardTypeId kTakeAwayCardTypeId = 6;
static const CardTypeId kReorderDeckCardTypeId = 7;
static const CardTypeId kFutureGlanceCardTypeId = 8;
static const CardTypeId kCatCard1TypeId = 9;
static const CardTypeId kCatCard2TypeId = 10;
static const CardTypeId kCatCard3TypeId = 11;
static const CardTypeId kCatCard4TypeId = 12;
static const CardTypeId kCatCard5TypeId = 13;

static const size_t kExplosiveCatCardCount = 1;
static const size_t kDefuseCardCount = 3;
static const size_t kDenyCardCount = 5;
static const size_t kAttackCardCount = 4;
static const size_t kSkipCardCount = 4;
static const size_t kTakeAwayCardCount = 4;
static const size_t kReorderDeckCardCount = 4;
static const size_t kFutureGlanceCardCount = 5;
static const size_t kCatCardsCount = 4;

static const size_t kCardsToDealCount = 6;

bool IsCardPlayable(CardTypeId type_id) {
    switch (type_id) {
        case kDenyCardTypeId:
        case kAttackCardTypeId:
        case kSkipCardTypeId:
        case kTakeAwayCardTypeId:
        case kReorderDeckCardTypeId:
        case kFutureGlanceCardTypeId:
            return true;
    }
    return false;
}

}
