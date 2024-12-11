#include "VtolItem.h"
#include "FuelConsumerComponent.h"
#include "Net/UnrealNetwork.h"

AVtolItem::AVtolItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CollisionMeshBottomOffset = 52.00f;
    this->CeilingCheckInterval = 0.15f;
    this->CeilingCheckHeight = 200.00f;
    this->AutoHoverHeight = 500.00f;
    this->LandingHeight = 500.00f;
    this->MaxLandingSlope = 25.00f;
    this->bMaintainHover = true;
    this->VerticalSpeedScalar = 0.50f;
    this->IgnitionDuration = 1.50f;
    this->TakeOffRotationInterpolationSpeed = 180.00f;
    this->ControlsInterpRate = 4.00f;
    this->MinLandingSpeedScalar = 0.15f;
    this->LandingSpeedInterpolationPercent = 0.15f;
    this->DoubleTapInputWindow = 0.75f;
    this->DoubleTapHoldThreshold = 0.15f;
    this->ControlsPromptDisplayDuration = 3.00f;
    this->ControlsPromptOpenDelay = 1.00f;
    this->ThrusterWashUpdateInterval = 0.25f;
    this->MaxSpeedForHighAltitudeWash = 0.20f;
    this->MovementComponent = NULL;
    this->CurrentForwardSpeedNormalized = 0.00f;
    this->CurrentLateralSpeedNormalized = 0.00f;
    this->bIsNearGround = true;
    this->FuelConsumerComponent = CreateDefaultSubobject<UFuelConsumerComponent>(TEXT("Fuel Consumer Component"));
    this->bEnginesActive = false;
    this->FuelAmount = 0.00f;
    this->bHasIgnition = false;
    this->MovementControlsPromptStatus = EControlsPromptStatus::PromptNotShown;
}

void AVtolItem::UpdateWashEffectsState() {
}



void AVtolItem::TimeoutTooltipOverride() {
}

void AVtolItem::SetRiseInputInactive() {
}

void AVtolItem::SetRiseInputActive() {
}

void AVtolItem::ServerSetNormalizedSpeeds_Implementation(float Forward, float lateral) {
}
bool AVtolItem::ServerSetNormalizedSpeeds_Validate(float Forward, float lateral) {
    return true;
}

void AVtolItem::ServerNotifyLandedChanged_Implementation(bool bLanded) {
}
bool AVtolItem::ServerNotifyLandedChanged_Validate(bool bLanded) {
    return true;
}

void AVtolItem::ServerNearGroundChanged_Implementation(bool bNearGround) {
}
bool AVtolItem::ServerNearGroundChanged_Validate(bool bNearGround) {
    return true;
}

void AVtolItem::ServerEnginesActivated_Implementation(bool bActivated, FLandingInfo LandingInfo) {
}
bool AVtolItem::ServerEnginesActivated_Validate(bool bActivated, FLandingInfo LandingInfo) {
    return true;
}

void AVtolItem::ServerConsumeFuel_Implementation(float Time) {
}
bool AVtolItem::ServerConsumeFuel_Validate(float Time) {
    return true;
}

void AVtolItem::RouteAux2ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType) {
}

void AVtolItem::RouteAux1ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType) {
}

void AVtolItem::OnSlottedItemsChanged() {
}

void AVtolItem::OnRep_IsNearGround(bool bPreviousValue) {
}

void AVtolItem::OnRep_FuelAmount() {
}

void AVtolItem::OnRep_EnginesActivated(bool bPreviousValue) {
}





void AVtolItem::OnFuelRecipeAmountChanged(float Amount) {
}



void AVtolItem::OnCreativeModeFreeFuelChanged(bool bFreeFuel) {
}

void AVtolItem::MulticastNotifyLandedChanged_Implementation(bool bLanded) {
}

bool AVtolItem::IsLocallyControlled() const {
    return false;
}

void AVtolItem::HandleVehicleUnmanned(AAstroPlayerController* OldPilot) {
}

void AVtolItem::HandleVehicleManned(AAstroPlayerController* NewPilot) {
}


ASolarBody* AVtolItem::GetLocalSolarBody() const {
    return NULL;
}

void AVtolItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AVtolItem, CurrentForwardSpeedNormalized);
    DOREPLIFETIME(AVtolItem, CurrentLateralSpeedNormalized);
    DOREPLIFETIME(AVtolItem, bIsNearGround);
    DOREPLIFETIME(AVtolItem, bEnginesActive);
    DOREPLIFETIME(AVtolItem, FuelAmount);
}


