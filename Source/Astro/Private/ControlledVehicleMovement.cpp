#include "ControlledVehicleMovement.h"
#include "Net/UnrealNetwork.h"

UControlledVehicleMovement::UControlledVehicleMovement(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MovingValue = 0.00f;
    this->TargetMovingValue = 0.00f;
    this->DoNotBindInputToControlComponent = false;
    this->RawThrottleValue = 0.00f;
    this->bAuthoritativeEnabled = false;
    this->bEnabled = false;
    this->bPhysicsEnabledCached = false;
    this->WheeledChassis = NULL;
}

void UControlledVehicleMovement::SetControlled(bool IsControlled) {
}

void UControlledVehicleMovement::SetAuthorityControlled_Implementation(bool IsControlled) {
}
bool UControlledVehicleMovement::SetAuthorityControlled_Validate(bool IsControlled) {
    return true;
}

void UControlledVehicleMovement::OnUnmanned() {
}

void UControlledVehicleMovement::OnMove(APlayerController* Controller, const FVector& Direction) {
}

void UControlledVehicleMovement::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UControlledVehicleMovement, bAuthoritativeEnabled);
}


