#include "ItemCatalogEntrySpindleDisplay.h"

class UMeshComponent;
class UStaticMeshComponent;
class UPrimitiveComponent;

void UItemCatalogEntrySpindleDisplay::SetItemIconMeshComponents(UMeshComponent* newItemIconMeshParent, const TArray<UStaticMeshComponent*>& newItemIconMeshComponents) {
}

void UItemCatalogEntrySpindleDisplay::ItemIconMeshClicked(UPrimitiveComponent* clickedComponent, FKey ButtonPressed) {
}

int32 UItemCatalogEntrySpindleDisplay::ContinuousIndexToItemIconMeshIndex(const int32 continuousIndex) const {
    return 0;
}

UItemCatalogEntrySpindleDisplay::UItemCatalogEntrySpindleDisplay() {
    this->bItemIconMeshesAreClickable = true;
    this->UnavailableItemIconMaterial = NULL;
    this->AvailableItemIconMaterial = NULL;
    this->UnlockedItemIconMaterial = NULL;
    this->ItemIconMeshParent = NULL;
    this->SelectedItemContinuousIndex = 0;
}

