#include "FlyingDroneMovementComponent.h"
#include "Net/UnrealNetwork.h"

void UFlyingDroneMovementComponent::SetCreativeModeFlightSpeedScalarNormalized(float NormalizedCreativeModeFlightSpeedScalar) {
}

void UFlyingDroneMovementComponent::ServerUpdateClientMovementInputVector_Implementation(FVector_NetQuantizeNormal ClientMovementInput) {
}
bool UFlyingDroneMovementComponent::ServerUpdateClientMovementInputVector_Validate(FVector_NetQuantizeNormal ClientMovementInput) {
    return true;
}

float UFlyingDroneMovementComponent::GetCreativeModeFlightSpeedScalarNormalized() {
    return 0.0f;
}

void UFlyingDroneMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UFlyingDroneMovementComponent, ClientMovementInputVector);
}

UFlyingDroneMovementComponent::UFlyingDroneMovementComponent() {
    this->MaxAcceleration = 5000.00f;
    this->MinCreativeModeFlightSpeedScalar = 1.00f;
    this->MaxCreativeModeFlightSpeedScalar = 5.00f;
    this->CreativeModeFlightSpeedScalar = 1.00f;
    this->DepenetrationStrength = 10.00f;
    this->UpdatedComponent = NULL;
    this->DroneOwner = NULL;
    this->RotationSpeed = 360.00f;
    this->GravitySourceInterpolationTime = 0.50f;
    this->PlayerCamera = NULL;
}

