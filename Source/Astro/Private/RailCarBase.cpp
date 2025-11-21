#include "RailCarBase.h"
#include "ControlComponent.h"
#include "Net/UnrealNetwork.h"

ARailCarBase::ARailCarBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaxSpeed = 500.00f;
    this->AccelerationRate = 1.20f;
    this->LowPowerSpeedMultiplier = 0.50f;
    this->LeftRightDeadzone = 0.10f;
    this->Length = 700.00f;
    this->SteeringControlDistance = 2000.00f;
    this->SteerablePostItemType = NULL;
    this->GaugeDynamicMaterialIndex = -1;
    this->WheelsDynamicMaterialIndex = -1;
    this->WheelRadius = 70.00f;
    this->CaravanSlotPositionComponent = NULL;
    this->CaravanConnectionSpline = NULL;
    this->GaugeMaterial = NULL;
    this->WheelMaterial = NULL;
    this->ControlComponent = CreateDefaultSubobject<UControlComponent>(TEXT("ControlComponent"));
    this->RailNetwork = NULL;
    this->bForceInvertOnEnds = false;
    this->StartTrainLoopAudioEvent = TEXT("play_train_loop");
    this->StopTrainLoopAudioEvent = TEXT("stop_train_loop");
    this->StartRecallAudioEvent = TEXT("play_recall_start_from_train");
    this->RecallInProgressAudioEvent = TEXT("play_recall_in_progress_from_train");
    this->StopRecallAudioEvent = TEXT("play_recall_disrupted");
    this->StartTrainBlockedAudioEvent = TEXT("play_train_blocked_start");
    this->StopTrainBlockedAudioEvent = TEXT("play_train_blocked_stop");
}

void ARailCarBase::ServerHandleDriverInput_Implementation(float SteeringInput, float ThrottleInput, bool isCameraBackwards) {
}

void ARailCarBase::RouteAux2ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> EventType) {
}

void ARailCarBase::RouteAux1ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> EventType) {
}

void ARailCarBase::OnRep_MovementData(FRailCarMovementReplicatedData Previous) {
}

void ARailCarBase::OnCarLostCursorFocus(UPrimitiveComponent* TouchedComponent) {
}

void ARailCarBase::OnCarGainedCursorFocus(UPrimitiveComponent* TouchedComponent) {
}


void ARailCarBase::MulticastOnPostConnectionsChanged_Implementation() {
}

bool ARailCarBase::IsRotationInverted() const {
    return false;
}

bool ARailCarBase::HasDesiredPath() const {
    return false;
}

void ARailCarBase::HandleVehicleUnmanned(AAstroPlayerController* oldDriver) {
}

void ARailCarBase::HandleVehicleManned(AAstroPlayerController* newDriver) {
}

void ARailCarBase::HandleUse() {
}

void ARailCarBase::HandleReleasedFromSlot() {
}

void ARailCarBase::HandleRailNetworkCreated() {
}

void ARailCarBase::HandlePlacedInSlot() {
}

void ARailCarBase::HandleClickQuery(UClickQuery* Query) {
}

void ARailCarBase::HandleCarReleasedFromCaravanSlot(APhysicalItem* Item) {
}

void ARailCarBase::HandleCarPlacedInCaravanSlot(APhysicalItem* Item) {
}

void ARailCarBase::HandleActuateUse(TEnumAsByte<EInputEvent> InputEvent, const UActuatorComponent* InActuatorComponent) {
}

float ARailCarBase::GetTotalCaravanPowerDraw() const {
    return 0.0f;
}

ERailCarMovementState ARailCarBase::GetMovementState() const {
    return ERailCarMovementState::Off;
}

int32 ARailCarBase::GetMaxCaravanLength() {
    return 0;
}

float ARailCarBase::GetForwardThrottleDirectionForDriver(APlayController* Driver, bool& isCameraBackwards) const {
    return 0.0f;
}

ASeatBase* ARailCarBase::GetFirstSlottedSeat() const {
    return NULL;
}

int32 ARailCarBase::GetCurrentCaravanLength() {
    return 0;
}

void ARailCarBase::ConsumeLeftTriggerToggle() {
}

bool ARailCarBase::CaravanHasDesiredPath() const {
    return false;
}

void ARailCarBase::AuthorityTryStartCar(bool swapDirections) {
}

void ARailCarBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARailCarBase, ReplicatedMovementData);
}


