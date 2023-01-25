#include "ResourceConsumptionLockingMechanism.h"

class AActor;
class APhysicalItem;

void UResourceConsumptionLockingMechanism::OnItemSetInResourceConsumptionSlot(APhysicalItem* Item) {
}

void UResourceConsumptionLockingMechanism::OnItemBeingConsumedDrained() {
}

void UResourceConsumptionLockingMechanism::OnItemBeingConsumedDestroyed(AActor* DestroyedActor) {
}

UResourceConsumptionLockingMechanism::UResourceConsumptionLockingMechanism() {
    this->ConsumedResourceUnits = 0;
    this->ItemBeingConsumed = NULL;
}

