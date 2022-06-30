#include "HornComponent.h"

void UHornComponent::OneOffSoundPlayed_Implementation() {
}

void UHornComponent::LoopSoundStopped_Implementation() {
}

void UHornComponent::LoopSoundStarted_Implementation() {
}

UHornComponent::UHornComponent() {
    this->HornType = EHornType::OneOffSound;
    this->MinActivationDuration = 1.00f;
}

