#include "FollowBehindModifierComponent.h"

UFollowBehindModifierComponent::UFollowBehindModifierComponent() {
    this->bScaleSpeedWithDistance = false;
    this->bScaleSpeedWithSpeed = false;
    this->NormalScaleDistance = 1000.00f;
    this->MaximumTargetSpeed = 400.00f;
}

