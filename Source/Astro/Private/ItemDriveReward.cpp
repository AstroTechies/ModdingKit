#include "ItemDriveReward.h"

FItemDriveReward::FItemDriveReward() {
    this->PlayFabRewardObject = NULL;
    this->CatalogUnlockRewardItemType = NULL;
    this->RewardThreshold = 0;
    this->RepeatingRewardInterval = 0;
    this->bIsSecondaryReward = false;
    this->StageIndex = 0;
}

