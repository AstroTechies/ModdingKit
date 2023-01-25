#include "CatalogModule.h"
#include "Templates/SubclassOf.h"
#include "TooltipComponent.h"

class UItemCatalogCategoryDefinition;
class UItemType;

void ACatalogModule::UnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItems) {
}

bool ACatalogModule::TrySelectItemType(const TSubclassOf<UItemType>& ItemTypeToSelect) {
    return false;
}

void ACatalogModule::SetCategoryScrollList(const TArray<UItemCatalogCategoryDefinition*>& categoryList) {
}

bool ACatalogModule::SetActiveCatalogCategory(const UItemCatalogCategoryDefinition* CategoryDefinition) {
    return false;
}

void ACatalogModule::ScrollVariants(int32 NumVariantsToScroll) {
}

void ACatalogModule::ScrollToVariant(int32 VariantIndex, EItemVariantType VariantType) {
}

void ACatalogModule::ScrollEntries(int32 NumEntriesToScroll) {
}

void ACatalogModule::ResearchPointBalanceChanged(float NewResearchPointBalance) {
}


void ACatalogModule::OnTooltipOverrideChanged() {
}



void ACatalogModule::OnCreativeModeCatalogUnlockedChanged() {
}

void ACatalogModule::OnCategoryRight() {
}

void ACatalogModule::OnCategoryLeft() {
}

void ACatalogModule::KnownItemsChanged(const TArray<TSubclassOf<UItemType>>& newKnownItems) {
}

ESelectedItemUnlockState ACatalogModule::GetSelectedItemUnlockState() const {
    return ESelectedItemUnlockState::Unlocked;
}

UItemType* ACatalogModule::GetSelectedItemType() const {
    return NULL;
}

UClass* ACatalogModule::GetSelectedItemPickupClass() {
    return NULL;
}

void ACatalogModule::ApplyPendingDisplayChanges() {
}

ACatalogModule::ACatalogModule() {
    this->ItemCatalog = NULL;
    this->ActiveCatalogEntryDisplayIndex = -1;
    this->ActiveCatalogCategory = NULL;
    this->ActiveCatalogEntryIndex = -1;
    this->MaximumCatalogEntryScrollSpeed = 2.00f;
    this->ActiveItemTypeVariantType = EItemVariantType::Pioneer;
    this->ActiveVariantItemTypeIndex = -1;
    this->MaximumVariantItemTypeScrollSpeed = 3.00f;
    this->DefaultSelectedItemType = NULL;
    this->TooltipComponent = CreateDefaultSubobject<UTooltipComponent>(TEXT("ToolTip"));
    this->IsCreativeCatalog = false;
    this->AllCatalogItemsCategory = NULL;
}

