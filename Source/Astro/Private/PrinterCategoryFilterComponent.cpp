#include "PrinterCategoryFilterComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UPrinterCategoryFilterComponent::UPrinterCategoryFilterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ItemCatalog = NULL;
    this->AllCatalogItemsCategory = NULL;
}

void UPrinterCategoryFilterComponent::SetPrinterIndex(int32 Index) {
}

void UPrinterCategoryFilterComponent::SetCurrentSelectionIndex(int32 Index) {
}

void UPrinterCategoryFilterComponent::RemoveT3FilteredBaseItemType(TSubclassOf<UItemType> ItemType) {
}

void UPrinterCategoryFilterComponent::RemoveT2FilteredBaseItemType(TSubclassOf<UItemType> ItemType) {
}

void UPrinterCategoryFilterComponent::RemoveT1FilteredBaseItemType(TSubclassOf<UItemType> ItemType) {
}

void UPrinterCategoryFilterComponent::RemoveSlottedT3Printer(APhysicalItem* printer) {
}

void UPrinterCategoryFilterComponent::RemoveSlottedT2Printer(APhysicalItem* printer) {
}

void UPrinterCategoryFilterComponent::RemoveSlottedT1Printer(APhysicalItem* printer) {
}

void UPrinterCategoryFilterComponent::OnRep_ReplicationData() {
}

void UPrinterCategoryFilterComponent::OnCreativeModeCatalogUnlockedChanged() {
}

void UPrinterCategoryFilterComponent::KnownItemsChanged(const TArray<TSubclassOf<UItemType>>& newKnownItems) {
}

int32 UPrinterCategoryFilterComponent::GetCurrentSelectionIndex() {
    return 0;
}

TArray<TSubclassOf<UItemType>> UPrinterCategoryFilterComponent::GetCategoryItemListForBastItemType(TSubclassOf<UItemType> BaseItemType) {
    return TArray<TSubclassOf<UItemType>>();
}

void UPrinterCategoryFilterComponent::AddT3FilteredBaseItemType(TSubclassOf<UItemType> ItemType) {
}

void UPrinterCategoryFilterComponent::AddT2FilteredBaseItemType(TSubclassOf<UItemType> ItemType) {
}

void UPrinterCategoryFilterComponent::AddT1FilteredBaseItemType(TSubclassOf<UItemType> ItemType) {
}

void UPrinterCategoryFilterComponent::AddSlottedT3Printer(APhysicalItem* printer) {
}

void UPrinterCategoryFilterComponent::AddSlottedT2Printer(APhysicalItem* printer) {
}

void UPrinterCategoryFilterComponent::AddSlottedT1Printer(APhysicalItem* printer) {
}

void UPrinterCategoryFilterComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPrinterCategoryFilterComponent, PrintFilterReplicatedState);
}


