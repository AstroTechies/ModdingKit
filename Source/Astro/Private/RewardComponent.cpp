#include "RewardComponent.h"

FRewardResult URewardComponent::SelectReward() {
    return FRewardResult{};
}

URewardComponent::URewardComponent() {
    this->SelectionTemplate = NULL;
    this->bAllowMultipleUnlocks = true;
}

