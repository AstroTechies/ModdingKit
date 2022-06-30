#include "SnailBuffMovementOverrideComponent.h"

USnailBuffMovementOverrideComponent::USnailBuffMovementOverrideComponent() {
    this->AddedSprintMaxSpeedScalar = 1.00f;
    this->AddedJumpImpulse = 0.00f;
    this->AddedBoostImpulse = 0.00f;
    this->AddedJumpImpulseScalar = 1.00f;
    this->bIgnoreCarryEncumbrance = false;
}

