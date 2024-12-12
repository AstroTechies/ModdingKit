#include "RewardState.h"
#include "Templates/SubclassOf.h"

URewardState::URewardState() {
}

bool URewardState::IsUnlocked(TSubclassOf<UItemType> ItemType) const {
    return false;
}

bool URewardState::IsKnown(TSubclassOf<UItemType> ItemType) const {
    return false;
}


