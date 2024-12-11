#include "DroneBase.h"
#include "FlyingDroneMovementComponent.h"
#include "Net/UnrealNetwork.h"

ADroneBase::ADroneBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MovementComponent = CreateDefaultSubobject<UFlyingDroneMovementComponent>(TEXT("FlyingDroneMovement"));
    this->PrevAstroViewTarget = NULL;
    this->flightState = EDroneFlightState::Docked;
    this->OldOwner = NULL;
    this->ZoomedInCameraFOV = 10.00f;
    this->ZoomedOutCameraFOV = 90.00f;
    this->DiscreteCameraZoomIncrement = 0.10f;
    this->DiscreteFlightSpeedIncrement = 0.10f;
    this->ZoomSFXReplayDelay = 1.00f;
    this->DockingRotationInterpolationStrength = 4.00f;
    this->UndockingRotationInterpolationStrength = 4.00f;
    this->DockingLocationInterpolationStrength = 0.40f;
    this->UndockingLocationInterpolationStrength = 0.40f;
    this->DockingScaleInterpolationStrength = 4.00f;
    this->UndockingScaleInterpolationStrength = 4.00f;
    this->AudioListener = NULL;
    this->fixedFOVModifier = NULL;
    this->LerpStrengthScaleFactor = 1.00f;
}

void ADroneBase::ZoomOut() {
}

void ADroneBase::ZoomIn() {
}


void ADroneBase::SetRiseInputInactive() {
}

void ADroneBase::SetRiseInputActive() {
}

void ADroneBase::ServerSetFlightState_Implementation(EDroneFlightState NewFlightState) {
}
bool ADroneBase::ServerSetFlightState_Validate(EDroneFlightState NewFlightState) {
    return true;
}

void ADroneBase::OnRep_FlightState() {
}

void ADroneBase::NudgeFlightSpeedSlower() {
}

void ADroneBase::NudgeFlightSpeedFaster() {
}

bool ADroneBase::IsLocallyControlled() const {
    return false;
}

void ADroneBase::HandlePlayerReachedSpaceInShuttle() {
}

void ADroneBase::HandlePlacedInSlot() {
}

void ADroneBase::HandleOutroCinematicCompleted() {
}

void ADroneBase::HandleOutroCinematicBecameActive() {
}

ASolarBody* ADroneBase::GetLocalSolarBody() const {
    return NULL;
}


float ADroneBase::GetCurrentFOV() const {
    return 0.0f;
}

void ADroneBase::AuthorityRecallDrone() {
}

void ADroneBase::AuthorityLaunchDrone(APlayController* OwningController) {
}

void ADroneBase::AuthorityEmergencyRecallDrone() {
}

void ADroneBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ADroneBase, flightState);
}


