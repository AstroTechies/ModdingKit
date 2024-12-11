#include "SlotStatics.h"
#include "Templates/SubclassOf.h"

USlotStatics::USlotStatics() {
}

bool USlotStatics::WillTakePhysicalItemToSlotArray(const TArray<FSlotReference>& Slots, APhysicalItem* Item) {
    return false;
}

int32 USlotStatics::WillAddItem(FSlotReference SlotRef, TSubclassOf<UItemType> Type, int32 Amount, float EjectForce) {
    return 0;
}

bool USlotStatics::TakeToSlotArray(const TArray<FSlotReference>& Slots, FSlotReference Other) {
    return false;
}

int32 USlotStatics::TakeSlotItemToComponent(UItemComponent* Component, FSlotReference Other, int32 Amount) {
    return 0;
}

int32 USlotStatics::TakeSlotItemRateToComponent(UItemComponent* Component, FSlotReference Other, float Rate) {
    return 0;
}

int32 USlotStatics::TakeSlotItemRateDeltaToComponent(UItemComponent* Component, FSlotReference Other, float Rate, float DeltaTime) {
    return 0;
}

int32 USlotStatics::TakeSlotItemRateDelta(FSlotReference Slot, FSlotReference Other, float Rate, float DeltaTime) {
    return 0;
}

int32 USlotStatics::TakeSlotItemRate(FSlotReference Slot, FSlotReference Other, float Rate) {
    return 0;
}

int32 USlotStatics::TakeSlotItem(FSlotReference Slot, FSlotReference Other, int32 Amount) {
    return 0;
}

bool USlotStatics::TakeSlotArrayPhysicalItemOfTypeToSlotArray(const TArray<FSlotReference>& FromSlots, const TArray<FSlotReference>& ToSlots, TSubclassOf<UItemType> Type, const TArray<APhysicalItem*> IgnoredItems) {
    return false;
}

bool USlotStatics::TakePhysicalItemToSlotArray(const TArray<FSlotReference>& Slots, APhysicalItem* Item, bool FromTool) {
    return false;
}

int32 USlotStatics::TakeItemToSlotArrayRateDelta(const TArray<FSlotReference>& Slots, FSlotReference Other, float Rate, float DeltaTime) {
    return 0;
}

int32 USlotStatics::TakeItemToSlotArrayRate(UObject* WorldContextObject, const TArray<FSlotReference>& Slots, FSlotReference Other, float Rate) {
    return 0;
}

int32 USlotStatics::TakeItemToSlotArray(const TArray<FSlotReference>& Slots, FSlotReference Other, int32 Amount) {
    return 0;
}

int32 USlotStatics::TakeItemRateDelta(FSlotReference Slot, TSubclassOf<UItemType> Type, float Rate, float DeltaTime) {
    return 0;
}

int32 USlotStatics::TakeItemRate(FSlotReference Slot, TSubclassOf<UItemType> Type, float Rate) {
    return 0;
}

int32 USlotStatics::TakeItemFromSlotArrayRateDelta(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, float Rate, float DeltaTime, int32 Max) {
    return 0;
}

int32 USlotStatics::TakeItemFromSlotArrayRate(UObject* WorldContextObject, const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, float Rate, int32 Max) {
    return 0;
}

int32 USlotStatics::TakeItemFromSlotArray(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, int32 Amount) {
    return 0;
}

int32 USlotStatics::TakeItem(FSlotReference Slot, TSubclassOf<UItemType> Type, int32 Amount) {
    return 0;
}

int32 USlotStatics::TakeComponentItemToSlot(FSlotReference SlotRef, UItemComponent* OtherComponent, int32 Amount) {
    return 0;
}

int32 USlotStatics::TakeComponentItemRateToSlot(FSlotReference SlotRef, UItemComponent* Other, float Rate) {
    return 0;
}

int32 USlotStatics::TakeComponentItemRateDeltaToSlot(FSlotReference SlotRef, UItemComponent* Other, float Rate, float DeltaTime) {
    return 0;
}

int32 USlotStatics::TakeAnyItemRateDelta(FSlotReference Slot, TSubclassOf<UItemType>& Type, float Rate, float DeltaTime) {
    return 0;
}

int32 USlotStatics::TakeAnyItemRate(FSlotReference Slot, TSubclassOf<UItemType>& Type, float Rate) {
    return 0;
}

int32 USlotStatics::TakeAnyItemFromSlotArrayRateDelta(const TArray<FSlotReference>& Slots, float Rate, float DeltaTime) {
    return 0;
}

int32 USlotStatics::TakeAnyItemFromSlotArrayRate(UObject* WorldContextObject, const TArray<FSlotReference>& Slots, float Rate) {
    return 0;
}

int32 USlotStatics::TakeAnyItemFromSlotArray(const TArray<FSlotReference>& Slots, int32 Amount) {
    return 0;
}

int32 USlotStatics::TakeAnyItem(FSlotReference Slot, TSubclassOf<UItemType>& Type, int32 Amount) {
    return 0;
}

bool USlotStatics::SpawnItemsInSlotArray(const TArray<FSlotReference>& Slots, const TArray<TSubclassOf<UItemType>>& ItemsToSpawn, TArray<APhysicalItem*>& OutSpawnedItems, bool packageItem) {
    return false;
}

int32 USlotStatics::SlotItemAmount(FSlotReference Slot, TSubclassOf<UItemType> Type) {
    return 0;
}

FSlotReference USlotStatics::SlotArraySlotWithItem(const TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type) {
    return FSlotReference{};
}

FSlotReference USlotStatics::SlotArraySlotWithAnyItem(const TArray<FSlotReference> Slots) {
    return FSlotReference{};
}

FSlotReference USlotStatics::SlotArraySlotForPhysicalItem(const TArray<FSlotReference> Slots, APhysicalItem* PhysicalItem) {
    return FSlotReference{};
}

FSlotReference USlotStatics::SlotArraySlotForItem(const TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type) {
    return FSlotReference{};
}

FSlotReference USlotStatics::SlotArrayQueryBestSlot(const TArray<FSlotReference> Slots, UClickQuery* Query) {
    return FSlotReference{};
}

FSlotReference USlotStatics::SlotArrayQueryBestFullSlot(const TArray<FSlotReference> Slots, UClickQuery* Query) {
    return FSlotReference{};
}

FSlotReference USlotStatics::SlotArrayQueryBestEmptySlot(const TArray<FSlotReference> Slots, UClickQuery* Query) {
    return FSlotReference{};
}

bool USlotStatics::SlotArrayHasItem(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type) {
    return false;
}

bool USlotStatics::SlotArrayHasAnyItem(const TArray<FSlotReference>& Slots) {
    return false;
}

APhysicalItem* USlotStatics::SlotArrayGetSlottedItemThatCanAcceptChangeInAmountForItemType(const TArray<FSlotReference>& itemSlots, TSubclassOf<UItemType> ItemType, bool changeIsPositive) {
    return NULL;
}

int32 USlotStatics::SlotArrayGetNumberOfSlottedItemsThatHaveItemType(const TArray<FSlotReference>& itemSlots, TSubclassOf<UItemType> ItemType) {
    return 0;
}

int32 USlotStatics::SlotArrayGetNumberOfEmptyContainers(const TArray<FSlotReference>& itemSlots, TSubclassOf<UItemType> typeToCheckAgainstStorageWhitelist) {
    return 0;
}

bool USlotStatics::SlotArrayGetItem(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, int32& Amount) {
    return false;
}

bool USlotStatics::SlotArrayGetAllSlottedItemsThatHaveType(const TArray<FSlotReference>& itemSlots, TArray<APhysicalItem*>& outItemArray, TSubclassOf<UItemType> ItemType) {
    return false;
}

bool USlotStatics::SlotArrayGetAllSlottedItemsThatCanAcceptChangeInAmountForItemType(const TArray<FSlotReference>& itemSlots, TArray<APhysicalItem*>& outItemArray, TSubclassOf<UItemType> ItemType, bool changeIsPositive) {
    return false;
}

bool USlotStatics::SlotArrayGetAllSlottedItemsThatAreEmptyContainers(const TArray<FSlotReference>& itemSlots, TSubclassOf<UItemType> typeToCheckAgainstStorageWhitelist, TArray<APhysicalItem*>& outEmptyContainerItems) {
    return false;
}

bool USlotStatics::SlotArrayGetAllSlottedItems(const TArray<FSlotReference>& itemSlots, TArray<APhysicalItem*>& outItemArray) {
    return false;
}

void USlotStatics::SlotArrayEnableClickable(const TArray<FSlotReference> Slots, bool clickable) {
}

FSlotReference USlotStatics::SlotArrayEmptySlot(const TArray<FSlotReference> Slots) {
    return FSlotReference{};
}

int32 USlotStatics::SlotArrayEmptyCount(const TArray<FSlotReference>& Slots) {
    return 0;
}

bool USlotStatics::MoveItemFromCurrentSlotToSlotArray(APhysicalItem* Item, const TArray<FSlotReference>& Slots) {
    return false;
}

bool USlotStatics::IsSlotAnAuxSlot(FSlotReference Slot) {
    return false;
}

bool USlotStatics::IsCompatibleWithType(FSlotReference Slot, TSubclassOf<UItemType> ItemType) {
    return false;
}

bool USlotStatics::IsAPowerCableSlot(FSlotReference SlotRef) {
    return false;
}

bool USlotStatics::HasSpaceAvailableAtTier(FSlotReference SlotRef, int32 Tier, bool AsIndicator) {
    return false;
}

bool USlotStatics::HasItem(FSlotReference Slot, TSubclassOf<UItemType> Type) {
    return false;
}

bool USlotStatics::HasFullResource(FSlotReference Slot) {
    return false;
}

bool USlotStatics::HasAnyItem(FSlotReference SlotRef) {
    return false;
}

UPrimitiveComponent* USlotStatics::GetVisualPrimitiveForIndicator(const FSlotReference& SlotRef, int32 SlotIndicatorIndex) {
    return NULL;
}

UTooltipComponent* USlotStatics::GetTooltipForSlot(FSlotReference SlotRef) {
    return NULL;
}

FTransform USlotStatics::GetSubslotTransform(FSlotReference SlotRef, int32 SubslotIndex) {
    return FTransform{};
}

TSubclassOf<UItemType> USlotStatics::GetStoredSubItemTypeClass(FSlotReference SlotRef) {
    return NULL;
}

UItemType* USlotStatics::GetStoredSubItemTypeCDO(FSlotReference SlotRef) {
    return NULL;
}

FVector USlotStatics::GetSlotRangeLocation(const FSlotReference& SlotRef) {
    return FVector{};
}

TSubclassOf<UItemList> USlotStatics::GetSlotItemFiltrationList(FSlotReference SlotRef) {
    return NULL;
}

TSubclassOf<UItemType> USlotStatics::GetPrimaryItemTypeClass(FSlotReference SlotRef) {
    return NULL;
}

UItemType* USlotStatics::GetPrimaryItemTypeCDO(FSlotReference SlotRef) {
    return NULL;
}

int32 USlotStatics::GetNumberOfDiscreteSlottedItems(FSlotReference SlotRef, const TSubclassOf<UItemType>& Type) {
    return 0;
}

TSubclassOf<UItemType> USlotStatics::GetItemTypeClass(FSlotReference SlotRef) {
    return NULL;
}

UItemType* USlotStatics::GetItemTypeCDO(FSlotReference SlotRef) {
    return NULL;
}

int32 USlotStatics::GetItemAmount(FSlotReference Slot, const TSubclassOf<UItemType>& Type) {
    return 0;
}

UTooltipComponent* USlotStatics::GetIndicatorTooltipForSlot(FSlotReference SlotRef, int32 SubslotIndex) {
    return NULL;
}

EAuxSlotType USlotStatics::GetAuxSlotType(FSlotReference SlotRef) {
    return EAuxSlotType::None;
}

bool USlotStatics::GetAnyItem(FSlotReference SlotRef, int32& Amount, TSubclassOf<UItemType>& Type) {
    return false;
}

TArray<APhysicalItem*> USlotStatics::GetAllItemsInConnectedStorage(AActor* baseActor) {
    return TArray<APhysicalItem*>();
}

int32 USlotStatics::FindSubslotOfItem(FSlotReference SlotRef, APhysicalItem* Item) {
    return 0;
}

int32 USlotStatics::FindFirstAvailableSubslot(FSlotReference SlotRef, int32 Tier, bool AsIndicator) {
    return 0;
}

void USlotStatics::EjectAllItemsInSubslotAndChildSubslots(FSlotReference SlotRef, int32 SubslotIndex, bool NewOwner, bool FromTool, float RandomForce) {
}

APhysicalItem* USlotStatics::CloneItemIntoSlot(APhysicalItem* ItemToClone, FSlotReference SlotToSpawnCloneIn) {
    return NULL;
}

bool USlotStatics::AttemptToPlacePrimaryItemInConnectedStorageSlotNetwork(FSlotReference SlotRef, AActor* ActorInStorageNetwork) {
    return false;
}

bool USlotStatics::AttemptToPlaceItemInConnectedStorageSlotNetwork(APhysicalItem* Item, AActor* ActorInStorageNetwork) {
    return false;
}

int32 USlotStatics::AddToSlotArrayRateDelta(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, float Rate, float DeltaTime) {
    return 0;
}

int32 USlotStatics::AddToSlotArrayRate(UObject* WorldContextObject, const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, float Rate) {
    return 0;
}

int32 USlotStatics::AddToSlotArray(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, int32 Amount) {
    return 0;
}

int32 USlotStatics::AddItemRateDelta(FSlotReference Slot, TSubclassOf<UItemType> Type, float Rate, float DeltaTime) {
    return 0;
}

int32 USlotStatics::AddItemRate(FSlotReference Slot, TSubclassOf<UItemType> Type, float Rate) {
    return 0;
}

int32 USlotStatics::AddItem(FSlotReference SlotRef, TSubclassOf<UItemType> Type, int32 Amount, float EjectForce) {
    return 0;
}


