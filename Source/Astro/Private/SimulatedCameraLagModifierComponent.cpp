#include "SimulatedCameraLagModifierComponent.h"

USimulatedCameraLagModifierComponent::USimulatedCameraLagModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LagDOF = ECameraDOF::Distance;
    this->MaxFollowLag = 0.00f;
    this->MinLagVelocity = 0.00f;
    this->MaxLagVelocity = 0.00f;
}


