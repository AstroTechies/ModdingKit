#include "ItemStatics.h"
#include "Templates/SubclassOf.h"

class APhysicalItem;
class UItemList;
class UItemType;
class UObject;

bool UItemStatics::WillCraftItem(const TArray<FSlotReference>& InputSlots, FSlotReference outputSlot, const TArray<TSubclassOf<UItemType>>& ItemTypes) {
    return false;
}

int32 UItemStatics::TryCraftItemDelta(const TArray<FSlotReference>& InputSlots, FSlotReference outputSlot, const TArray<TSubclassOf<UItemType>>& ItemTypes, float Rate, float DeltaTime) {
    return 0;
}

int32 UItemStatics::TryCraftItem(const TArray<FSlotReference>& InputSlots, FSlotReference outputSlot, const TArray<TSubclassOf<UItemType>>& ItemTypes, float Rate) {
    return 0;
}

APhysicalItem* UItemStatics::SpawnDeployablePackagedItem(const UObject* WorldContextObject, TSubclassOf<APhysicalItem> PhysicalItemClassPackagedItemWillContain, FTransform SpawnTransform) {
    return NULL;
}

int32 UItemStatics::SmallItemAmountDelta() {
    return 0;
}

bool UItemStatics::ResourcePassesFiltrationList(TSubclassOf<UItemType> ItemToTest, TSubclassOf<UItemList> FiltrationList, ESlottableItemsFiltrationListBehavior FiltrationBehavior) {
    return false;
}

bool UItemStatics::RemoveItemFromBundleAndPlaceOnGroundNearby(APhysicalItem* BundledItem, FVector OffsetForGroundUnbundling, bool bPretendAsIfInAuxSlot) {
    return false;
}

float UItemStatics::RecipeFromAmount(int32 Amount) {
    return 0.0f;
}

UItemType* UItemStatics::PhysicalItemTypeCDO(TSubclassOf<APhysicalItem> PhysicalItemClass) {
    return NULL;
}

bool UItemStatics::PhysicalItemResetItemStartingAmountAndCapacityToClassDefaults(APhysicalItem* PhysicalItem) {
    return false;
}

TSubclassOf<UItemType> UItemStatics::PhysicalItemGetDefaultLiteralItemTypeClass(TSubclassOf<APhysicalItem> PhysicalItemClass) {
    return NULL;
}

APhysicalItem* UItemStatics::PhysicalItemDefault(TSubclassOf<APhysicalItem> PhysicalItemClass) {
    return NULL;
}

FRecipe UItemStatics::MakeItemRecipeFromSlots(const TArray<FSlotReference>& itemSlots) {
    return FRecipe{};
}

FRecipe UItemStatics::MakeItemRecipe(const TArray<TSubclassOf<UItemType>>& ItemTypes) {
    return FRecipe{};
}

int32 UItemStatics::ItemUnitAmount() {
    return 0;
}

bool UItemStatics::IsScannableStatusValid(FScannableStatus Status) {
    return false;
}

bool UItemStatics::IsRecipeValid(const FRecipe& Recipe) {
    return false;
}

bool UItemStatics::IsPackageableItemType(TSubclassOf<UItemType> ItemType) {
    return false;
}

bool UItemStatics::IsItemTypeOnlyStoredInContainers(TSubclassOf<UItemType> ItemType) {
    return false;
}

bool UItemStatics::IsItemPartOfRecipe(const FRecipe& Recipe, TSubclassOf<UItemType> ItemType) {
    return false;
}

bool UItemStatics::IsDeployablePackageItemType(TSubclassOf<UItemType> ItemType) {
    return false;
}

bool UItemStatics::IsContainerItemType(TSubclassOf<UItemType> ItemType) {
    return false;
}

FText UItemStatics::GetUseContextVerb(EUseContext Context) {
    return FText::GetEmpty();
}

TSubclassOf<APhysicalItem> UItemStatics::GetPackageTypeForItem(APhysicalItem* ItemToPackage) {
    return NULL;
}

FText UItemStatics::GetExamineVerb() {
    return FText::GetEmpty();
}

FText UItemStatics::GetCraftingSourcesTooltipDescription(TSubclassOf<UItemType> Item) {
    return FText::GetEmpty();
}

TSubclassOf<UItemType> UItemStatics::FindRecipeTarget(const FRecipe& Recipe, const TArray<TSubclassOf<UItemType>>& ItemTypes) {
    return NULL;
}

void UItemStatics::DestroyItemAndAllSlottedItemsRecursively(APhysicalItem* ItemToDestroy) {
}

int32 UItemStatics::ConvertDeformationDeltaToSedimentAmount(float deformationDelta, float SedimentDeformationRatio) {
    return 0;
}

bool UItemStatics::CanSwapHeldItemWithSlottedItem(const APhysicalItem* HeldItem, const APhysicalItem* SlottedItem) {
    return false;
}

bool UItemStatics::CanHeldItemInteractWithTargetItem(const APhysicalItem* HeldItem, const APhysicalItem* hitItem, bool& outHighlightChildrenOfTarget) {
    return false;
}

int32 UItemStatics::AmountFromRecipe(float Amount) {
    return 0;
}

int32 UItemStatics::AmountFromRate(float Rate, float DeltaSeconds) {
    return 0;
}

UItemStatics::UItemStatics() {
}

