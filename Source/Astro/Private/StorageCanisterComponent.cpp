#include "StorageCanisterComponent.h"
#include "Templates/SubclassOf.h"

class APhysicalItem;
class UItemComponent;
class UItemType;

void UStorageCanisterComponent::OnSlottedItemsChanged(APhysicalItem* changedItem) {
}

void UStorageCanisterComponent::OnItemTypeChanged(UItemComponent* ItemComponent, TSubclassOf<UItemType> NewItemType) {
}

void UStorageCanisterComponent::OnAmountChanged() {
}

void UStorageCanisterComponent::HandleSlotEvent(APhysicalItem* Item) {
}

void UStorageCanisterComponent::HandleOnReleasedFromSlot(bool NewOwner) {
}

void UStorageCanisterComponent::HandleOnPlacedInSlot() {
}

bool UStorageCanisterComponent::CanMoveItems() const {
    return false;
}

void UStorageCanisterComponent::AuthoritySetIsDispensing(bool isDispensing) {
}

void UStorageCanisterComponent::AuthorityQueueStopDispensingWhenItemComplete() {
}

UStorageCanisterComponent::UStorageCanisterComponent() {
    this->CurrentOuterMostChassis = NULL;
    this->ItemTransferRate = 1.00f;
}

