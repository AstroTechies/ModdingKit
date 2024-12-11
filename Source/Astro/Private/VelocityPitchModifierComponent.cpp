#include "VelocityPitchModifierComponent.h"

UVelocityPitchModifierComponent::UVelocityPitchModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->VelocitySmoothing = 1.00f;
    this->SaturationSpeed = 1000.00f;
}


