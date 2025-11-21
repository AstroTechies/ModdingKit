#include "ResourceConsumptionLockingMechanism.h"
#include "Templates/SubclassOf.h"

UResourceConsumptionLockingMechanism::UResourceConsumptionLockingMechanism() {
    this->ConsumedResourceUnits = 0;
    this->ItemBeingConsumed = NULL;
}

void UResourceConsumptionLockingMechanism::OnItemSetInResourceConsumptionSlot(APhysicalItem* Item) {
}

void UResourceConsumptionLockingMechanism::OnItemBeingConsumedDrained(TSubclassOf<UItemType> ItemType) {
}

void UResourceConsumptionLockingMechanism::OnItemBeingConsumedDestroyed(AActor* DestroyedActor) {
}


