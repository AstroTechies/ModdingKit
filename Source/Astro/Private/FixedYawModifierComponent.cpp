#include "FixedYawModifierComponent.h"

UFixedYawModifierComponent::UFixedYawModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UpperLimit = 90.00f;
    this->LowerLimit = -90.00f;
    this->TargetSpeed = 500.00f;
    this->RelativeToTarget = true;
    this->bScaleSpeedWithSpeed = false;
}


