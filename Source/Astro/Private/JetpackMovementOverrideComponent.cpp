#include "JetpackMovementOverrideComponent.h"

UJetpackMovementOverrideComponent::UJetpackMovementOverrideComponent() {
    this->AllJetpacksThrustVertical = 70.00f;
    this->SingleJetpackThrustVertical = 110.00f;
    this->AllJetpacksThrustForward = 70.00f;
    this->BonusHoverboardThrustForward = 0.00f;
    this->SingleJetpackThrustForward = 110.00f;
    this->AllJetpacksVerticalSpeedScalar = 2.50f;
    this->SingleJetpackVerticalSpeedScalar = 1.50f;
    this->AllJetpacksForwardSpeedScalar = 2.50f;
    this->SingleJetpackForwardSpeedScalar = 1.50f;
    this->BonusHoverboardForwardSpeedScalar = 0.00f;
    this->MaxJetpackCount = 2;
    this->ThrustDirectionChangeRate = 0.50f;
    this->MaxForwardAccelerationPercent = 0.15f;
    this->CustomGravityScaler = 0.00f;
    this->UseCustomGravityScalar = true;
}

