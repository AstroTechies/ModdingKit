#include "FixedPitchModifierComponent.h"

UFixedPitchModifierComponent::UFixedPitchModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UpperLimit = 20.00f;
    this->LowerLimit = -45.00f;
}


