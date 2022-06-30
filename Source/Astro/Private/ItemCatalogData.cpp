#include "ItemCatalogData.h"

UItemCatalogData::UItemCatalogData() {
    this->bIsCreativeModeOnly = false;
    this->bCreativeSpawnPackaged = false;
    this->bHiddenUntilUnlocked = false;
    this->bHiddenUntilUnlockedCreativeMode = false;
    this->UnlockCost = 1000;
    this->bIsBaseItem = true;
    this->Category = NULL;
    this->CategorySequenceNumber = 0;
    this->BaseItemType = NULL;
    this->VariantType = EItemVariantType::Pioneer;
    this->VariationSequenceNumber = 0;
    this->CatalogMesh = NULL;
}

