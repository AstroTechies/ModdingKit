#include "StorageCanisterComponent.h"
#include "Templates/SubclassOf.h"

UStorageCanisterComponent::UStorageCanisterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CanReingestFromOuputSlot = false;
    this->CurrentOuterMostChassis = NULL;
    this->ItemTransferRate = 1.00f;
}

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

bool UStorageCanisterComponent::GetIsDispensing() const {
    return false;
}

bool UStorageCanisterComponent::CanMoveItems() const {
    return false;
}

void UStorageCanisterComponent::AuthoritySetIsDispensing(bool isDispensing) {
}

void UStorageCanisterComponent::AuthorityQueueStopDispensingWhenItemComplete() {
}


