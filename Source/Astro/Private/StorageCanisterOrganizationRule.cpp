#include "StorageCanisterOrganizationRule.h"
#include "Templates/SubclassOf.h"

UStorageCanisterOrganizationRule::UStorageCanisterOrganizationRule() {
}

void UStorageCanisterOrganizationRule::SetStoredItemTypeWhitelist(TArray<TSubclassOf<UItemType>> itemTypes) {
}

void UStorageCanisterOrganizationRule::SetIsInputRule(bool isInput) {
}

void UStorageCanisterOrganizationRule::SetDispensing(bool isDispensing) {
}

void UStorageCanisterOrganizationRule::SetCurrentStoredItemType(TSubclassOf<UItemType> ItemType) {
}

void UStorageCanisterOrganizationRule::OnSlottedItemDrainedOrFilled() {
}


