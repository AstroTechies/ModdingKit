#include "SimulatedCameraLagModifierComponent.h"

USimulatedCameraLagModifierComponent::USimulatedCameraLagModifierComponent() {
    this->LagDOF = ECameraDOF::Distance;
    this->MaxFollowLag = 0.00f;
    this->MinLagVelocity = 0.00f;
    this->MaxLagVelocity = 0.00f;
}

