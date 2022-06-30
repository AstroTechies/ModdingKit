#include "RailCarBase.h"
#include "Net/UnrealNetwork.h"
#include "ControlComponent.h"

class AAstroPlayerController;
class UClickQuery;
class APhysicalItem;

void ARailCarBase::ServerHandleDriverInput_Implementation(float SteeringInput, float ThrottleInput) {
}

void ARailCarBase::RouteAux2ToggleUse(AAstroPlayerController* Controller, EInputEvent eventType) {
}

void ARailCarBase::RouteAux1ToggleUse(AAstroPlayerController* Controller, EInputEvent eventType) {
}

void ARailCarBase::OnRep_MovementData(FRailCarMovementReplicatedData Previous) {
}

bool ARailCarBase::IsRotationInverted() const {
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

void ARailCarBase::HandleClickQueryMutable(UClickQuery* Query) {
}

void ARailCarBase::HandleCarReleasedFromCaravanSlot(APhysicalItem* Item) {
}

void ARailCarBase::HandleCarPlacedInCaravanSlot(APhysicalItem* Item) {
}

void ARailCarBase::AuthorityTryStartCar(bool swapDirections) {
}

void ARailCarBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARailCarBase, ReplicatedMovementData);
}

ARailCarBase::ARailCarBase() {
    this->ControlComponent = CreateDefaultSubobject<UControlComponent>(TEXT("ControlComponent"));
    this->MaxSpeed = 500.00f;
    this->DrivingControlSensitivity = 0.70f;
    this->LeftRightDeadzone = 0.10f;
    this->MinSpeedMultiplier = 0.10f;
    this->Length = 700.00f;
    this->CaravanSlotPositionComponent = NULL;
    this->CaravanConnectionSpline = NULL;
    this->RailNetwork = NULL;
}

