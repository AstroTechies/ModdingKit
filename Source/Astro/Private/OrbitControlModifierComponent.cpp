#include "OrbitControlModifierComponent.h"

UOrbitControlModifierComponent::UOrbitControlModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UsePlanetUp = false;
    this->AffectRotation = false;
    this->PitchRate = 360.00f;
    this->YawRate = 720.00f;
    this->GamepadRotateMultiplier = 0.30f;
    this->MouseSmoothingFactor = 0.00f;
    this->GamepadSmoothingFactor = 0.00f;
    this->LookatHeightOffset = 0.00f;
}


