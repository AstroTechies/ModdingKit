#include "RailPostComponent.h"
#include "Net/UnrealNetwork.h"
#include "ActuatorComponent.h"

class UPrimitiveComponent;
class APhysicalItem;
class UClickQuery;

void URailPostComponent::ServerSetIsSnappedToRail_Implementation() {
}

void URailPostComponent::OnRep_ShouldStopOnArrival() {
}

void URailPostComponent::OnRep_IsMovable() {
}

void URailPostComponent::OnRep_CalledCarState(FCalledCarState PreviousState) {
}

void URailPostComponent::MulticastSetConnectionState_Implementation(ERailPostConnectionState ConnectionState) {
}

bool URailPostComponent::IsCarRecallInProgress() const {
    return false;
}

bool URailPostComponent::HasTraversingCars() const {
    return false;
}

void URailPostComponent::HandleRailNetworkCreated() {
}

void URailPostComponent::HandlePowerChanged(const FStreamingPowerNodeVisualizationData& powerData) {
}

void URailPostComponent::HandlePickedUp(bool isPhysicalMovement) {
}

void URailPostComponent::HandleIsAttachedToTerrainChanged() {
}

void URailPostComponent::HandleDroppedDelayed() {
}

void URailPostComponent::HandleDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal) {
}

void URailPostComponent::HandleDeformCompleted(float DensityDelta) {
}

void URailPostComponent::HandleClickQuery(UClickQuery* Query) {
}

void URailPostComponent::AuthorityTriggerUseOnStoppedCar() {
}

void URailPostComponent::AuthorityHandleOxygenChanged(bool hasOxygen) {
}

void URailPostComponent::AuthorityHandleItemPlacedInCaravanSlot(APhysicalItem* Item) {
}

void URailPostComponent::AuthorityCallCar() {
}

void URailPostComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(URailPostComponent, TraversingCars);
    DOREPLIFETIME(URailPostComponent, CalledCarState);
    DOREPLIFETIME(URailPostComponent, bIsMovable);
    DOREPLIFETIME(URailPostComponent, bShouldStopOnArrival);
}

URailPostComponent::URailPostComponent() {
    this->GaugeDynamicMaterialIndex = -1;
    this->RecallStartSound = TEXT("play_recall_start");
    this->RecallCancelSound = TEXT("play_recall_cancelled");
    this->RecallFailSound = TEXT("play_recall_failed");
    this->RecallCompleteSound = TEXT("play_recall_complete");
    this->ActuatorComponent = CreateDefaultSubobject<UActuatorComponent>(TEXT("Actuator"));
    this->GaugeMaterial = NULL;
    this->CalledCar = NULL;
    this->bIsMovable = true;
    this->bShouldStopOnArrival = false;
    this->bHasBeenInitialized = false;
}

