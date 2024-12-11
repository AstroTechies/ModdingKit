#include "RoverBase.h"
#include "ControlledVehicleMovement.h"

ARoverBase::ARoverBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TunnelBoringDeformerBaseScale = 0.00f;
    this->MaximumDisplaySeatedFlipPromptVelocity = 100.00f;
    this->MinimumSeatedHideFlipPromptVelocity = 1000.00f;
    this->ControlledVehicleMovement = CreateDefaultSubobject<UControlledVehicleMovement>(TEXT("ControlledVehicleMovement"));
    this->WheeledChassisComponent = NULL;
    this->StorageChassisComponent = NULL;
    this->UseSuppressionID = TEXT("RoverBase");
    this->bIsFlipped = false;
}

void ARoverBase::UpdateUseSuppression_Implementation(bool ShouldBeSuppressed) {
}

void ARoverBase::UpdateTunnelBoringOriginInternal(USceneComponent* FrontRightWheel, USceneComponent* FrontLeftWheel, USceneComponent* BackRightWheel, USceneComponent* BackLeftWheel, bool IsFrontMountedDrill, USceneComponent* TunnelBoringOrigion) {
}


void ARoverBase::ServerReceiveSeatExitOverriddenWithFlip_Implementation(bool ExitOverridden) {
}
bool ARoverBase::ServerReceiveSeatExitOverriddenWithFlip_Validate(bool ExitOverridden) {
    return true;
}

void ARoverBase::RouteAux2ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType) {
}

void ARoverBase::RouteAux1ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType) {
}

void ARoverBase::HandleVehicleUnmanned(AAstroPlayerController* OldPilot) {
}

void ARoverBase::HandleVehicleManned(AAstroPlayerController* NewPilot) {
}


void ARoverBase::EngageRollYawModifier() {
}

void ARoverBase::DisengageRollYawModifier() {
}

void ARoverBase::ConsumeLeftTriggerToggle() {
}

bool ARoverBase::Authority_GetSeatExitOverriddenWithFlip() const {
    return false;
}


