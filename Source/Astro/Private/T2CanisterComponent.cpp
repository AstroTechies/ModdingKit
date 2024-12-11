#include "T2CanisterComponent.h"
#include "Templates/SubclassOf.h"

UT2CanisterComponent::UT2CanisterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ItemTransferRate = 1.00f;
}

void UT2CanisterComponent::OnSlottedItemsChanged(APhysicalItem* changedItem) {
}

void UT2CanisterComponent::OnItemTypeChanged(UItemComponent* ItemComponent, TSubclassOf<UItemType> NewItemType) {
}

void UT2CanisterComponent::OnAmountChanged() {
}

bool UT2CanisterComponent::CanMoveItems() const {
    return false;
}

void UT2CanisterComponent::AuthoritySetIsDispensing(bool isDispensing) {
}


