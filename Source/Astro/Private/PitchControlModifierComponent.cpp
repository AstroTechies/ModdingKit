#include "PitchControlModifierComponent.h"

UPitchControlModifierComponent::UPitchControlModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Speed = 360.00f;
    this->GamepadMultiplier = 0.30f;
    this->MouseSmoothingFactor = 0.00f;
    this->GamepadSmoothingFactor = 0.00f;
    this->GamepadDeadZone = 0.01f;
    this->UpperLimit = 90.00f;
    this->LowerLimit = -90.00f;
    this->SpongeRange = 0.00f;
    this->ControlMask = ECameraControlMask::All;
}


