#include "FollowBehindModifierComponent.h"

UFollowBehindModifierComponent::UFollowBehindModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bScaleSpeedWithDistance = false;
    this->bScaleSpeedWithSpeed = false;
    this->NormalScaleDistance = 1000.00f;
    this->MaximumTargetSpeed = 400.00f;
}


