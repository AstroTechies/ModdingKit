#include "HornComponent.h"

UHornComponent::UHornComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HornType = EHornType::OneOffSound;
    this->MinActivationDuration = 1.00f;
}

void UHornComponent::OneOffSoundPlayed_Implementation() {
}

void UHornComponent::LoopSoundStopped_Implementation() {
}

void UHornComponent::LoopSoundStarted_Implementation() {
}


