#include "YawControlModifierComponent.h"

UYawControlModifierComponent::UYawControlModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Speed = 720.00f;
    this->GamepadMultiplier = 0.30f;
    this->MouseSmoothingFactor = 0.00f;
    this->GamepadSmoothingFactor = 0.00f;
    this->GamepadDeadZone = 0.01f;
    this->ControlMask = ECameraControlMask::All;
}


