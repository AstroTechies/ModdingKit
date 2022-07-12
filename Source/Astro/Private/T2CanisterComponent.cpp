#include "T2CanisterComponent.h"
#include "Templates/SubclassOf.h"

class UItemType;
class APhysicalItem;
class UItemComponent;

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

UT2CanisterComponent::UT2CanisterComponent() {
    this->ItemTransferRate = 1.00f;
}

