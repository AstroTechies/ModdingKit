#include "RewardComponent.h"

URewardComponent::URewardComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SelectionTemplate = NULL;
    this->bAllowMultipleUnlocks = true;
}

FRewardResult URewardComponent::SelectReward() {
    return FRewardResult{};
}


