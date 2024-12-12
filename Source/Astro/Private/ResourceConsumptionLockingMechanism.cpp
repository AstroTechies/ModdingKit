#include "ResourceConsumptionLockingMechanism.h"

UResourceConsumptionLockingMechanism::UResourceConsumptionLockingMechanism() {
    this->ConsumedResourceUnits = 0;
    this->ItemBeingConsumed = NULL;
}

void UResourceConsumptionLockingMechanism::OnItemSetInResourceConsumptionSlot(APhysicalItem* Item) {
}

void UResourceConsumptionLockingMechanism::OnItemBeingConsumedDrained() {
}

void UResourceConsumptionLockingMechanism::OnItemBeingConsumedDestroyed(AActor* DestroyedActor) {
}


