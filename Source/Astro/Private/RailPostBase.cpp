#include "RailPostBase.h"
#include "Net/UnrealNetwork.h"
#include "ActuatorComponent.h"

class UPrimitiveComponent;
class UClickQuery;
class APhysicalItem;

void ARailPostBase::OnRep_ShouldStopOnArrival() {
}

void ARailPostBase::OnRep_IsMovable() {
}

void ARailPostBase::HandleUse() {
}

void ARailPostBase::HandlePickedUp(bool isPhysicalMovement) {
}

void ARailPostBase::HandleDroppedDelayed() {
}

void ARailPostBase::HandleDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal) {
}

void ARailPostBase::HandleClickQuery(UClickQuery* Query) {
}

void ARailPostBase::AuthorityHandleOxygenChanged(bool hasOxygen) {
}

void ARailPostBase::AuthorityHandleItemPlacedInCaravanSlot(APhysicalItem* Item) {
}

void ARailPostBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARailPostBase, TraversingCars);
    DOREPLIFETIME(ARailPostBase, bIsMovable);
    DOREPLIFETIME(ARailPostBase, bShouldStopOnArrival);
}

ARailPostBase::ARailPostBase() {
    this->ActuatorComponent = CreateDefaultSubobject<UActuatorComponent>(TEXT("Actuator"));
    this->bIsMovable = true;
    this->bShouldStopOnArrival = false;
    this->bHasBeenInitialized = false;
}

