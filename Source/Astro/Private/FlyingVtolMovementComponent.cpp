#include "FlyingVtolMovementComponent.h"
#include "Net/UnrealNetwork.h"

class UCameraComponent;

void UFlyingVtolMovementComponent::SetFlightSpeedScalarNormalized(float normalizedFlightSpeedScalar) {
}

void UFlyingVtolMovementComponent::SetControllingCamera(UCameraComponent* controllingCamera) {
}

void UFlyingVtolMovementComponent::ServerUpdateClientMovementInputVector_Implementation(FVector_NetQuantizeNormal ClientMovementInput) {
}
bool UFlyingVtolMovementComponent::ServerUpdateClientMovementInputVector_Validate(FVector_NetQuantizeNormal ClientMovementInput) {
    return true;
}

float UFlyingVtolMovementComponent::GetFlightSpeedScalarNormalized() {
    return 0.0f;
}

void UFlyingVtolMovementComponent::DelayedGravitySourceRemoval() {
}

void UFlyingVtolMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UFlyingVtolMovementComponent, ClientMovementInputVector);
}

UFlyingVtolMovementComponent::UFlyingVtolMovementComponent() {
    this->MaxAcceleration = 5000.00f;
    this->MinFlightSpeedScalar = 1.00f;
    this->MaxFlightSpeedScalar = 5.00f;
    this->FullSpeedPercent = 0.90f;
    this->CruisingModeFullSpeedStartTime = 3.00f;
    this->CruisingModeFullSpeedEndTime = 6.00f;
    this->CruisingModeAirBrakeTime = 1.00f;
    this->NearGroundAirBrakeDelay = 1.00f;
    this->DepenetrationStrength = 10.00f;
    this->UpdatedComponent = NULL;
    this->VTOLOwner = NULL;
    this->RotationSpeed = 360.00f;
    this->CruisingModeRotationSpeed = 180.00f;
    this->RotationSpeedLerpRate = 90.00f;
    this->GravitySourceInterpolationTime = 0.50f;
    this->PlayerCamera = NULL;
}

