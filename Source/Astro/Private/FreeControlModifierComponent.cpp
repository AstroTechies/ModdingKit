#include "FreeControlModifierComponent.h"

UFreeControlModifierComponent::UFreeControlModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TranslateSpeed = 0.00f;
    this->MaxBoostMultiplier = 10.00f;
    this->PitchRate = 360.00f;
    this->YawRate = 720.00f;
    this->GamepadRotateMultiplier = 0.30f;
}


