#include "RewardSystem.h"
#include "Templates/SubclassOf.h"

class AActor;
class UItemType;

FRewardResult URewardSystem::SelectReward(const FRewardSelectionParameters& params) {
    return FRewardResult{};
}

bool URewardSystem::MarkActorTypeAsResearched(TSubclassOf<AActor> actorType) {
    return false;
}

bool URewardSystem::HasActorTypeBeenResearched(TSubclassOf<AActor> actorType) const {
    return false;
}

bool URewardSystem::GrantDurable(TSubclassOf<UItemType> itemToUnlock) {
    return false;
}

URewardSystem::URewardSystem() {
    this->RewardState = NULL;
    this->RewardTable = NULL;
}

