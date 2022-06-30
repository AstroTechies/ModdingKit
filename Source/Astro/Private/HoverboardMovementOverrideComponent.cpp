#include "HoverboardMovementOverrideComponent.h"

UHoverboardMovementOverrideComponent::UHoverboardMovementOverrideComponent() {
    this->MaxSpeedScalar = 0.00f;
    this->MaxThrust = 0.00f;
    this->DismountDelayTime = 1.00f;
    this->FlatFallDamageScalar = 1.00f;
    this->bFallDamageExponentialDecay = false;
    this->MinImpactSlopeAngle = 30.00f;
    this->bImmuneToFallDamage = false;
}

