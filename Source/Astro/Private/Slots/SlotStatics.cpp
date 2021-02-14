// Fill out your copyright notice in the Description page of Project Settings.

#include "SlotStatics.h"


bool USlotStatics::SpawnItemsInSlotArray(TArray<FSlotReference> slots, TArray<TSubclassOf<UItemType>> itemsToSpawn, TArray<APhysicalItem *> outSpawnedItems)
{
	return false;
}

int USlotStatics::SlotArrayEmptyCount(TArray<FSlotReference> Slots)
{
	return 0;
}

int USlotStatics::AddToSlotArray(TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, int Amount)
{
	return 0;
}

int USlotStatics::AddToSlotArrayRate(UObject* WorldContextObject, TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, float Rate)
{
	return 0;
}

int USlotStatics::AddToSlotArrayRateDelta(TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, float Rate, float DeltaTime)
{
	return 0;
}

bool USlotStatics::TakeToSlotArray(TArray<FSlotReference> Slots, FSlotReference Other)
{
	return false;
}

int USlotStatics::TakeItemFromSlotArray(TArray<FSlotReference> Slots, TSubclassOf<UItemType> ItemType, int Amount)
{
	return 0;
}

int USlotStatics::TakeAnyItemFromSlotArray(TArray<FSlotReference> Slots, int Amount)
{
	return 0;
}

int USlotStatics::TakeItemFromSlotArrayRate(UObject* WorldContextObject, TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, float Rate, int Max)
{
	return 0;
}

int USlotStatics::TakeItemFromSlotArrayRateDelta(TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, float Rate, float DeltaTime, int Max)
{
	return 0;
}

int USlotStatics::TakeAnyItemFromSlotArrayRate(UObject* WorldContextObject, TArray<FSlotReference> Slots, float Rate)
{
	return 0;
}

int USlotStatics::TakeAnyItemFromSlotArrayRateDelta(TArray<FSlotReference> Slots, float Rate, float DeltaTime)
{
	return 0;
}

int USlotStatics::TakeItemToSlotArray(TArray<FSlotReference> Slots, FSlotReference Other, int Amount)
{
	return 0;
}

bool USlotStatics::TakePhysicalItemToSlotArray(TArray<FSlotReference> Slots, APhysicalItem* Item, bool FromTool)
{
	return false;
}

bool USlotStatics::TakeSlotArrayPhysicalItemOfTypeToSlotArray(TArray<FSlotReference> FromSlots, TArray<FSlotReference> ToSlots, TSubclassOf<UItemType> Type, TArray<APhysicalItem *> IgnoredItems)
{
	return false;
}

bool USlotStatics::WillTakePhysicalItemToSlotArray(TArray<FSlotReference> Slots, APhysicalItem* Item)
{
	return false;
}

int USlotStatics::TakeItemToSlotArrayRate(UObject* WorldContextObject, TArray<FSlotReference> Slots, FSlotReference Other, float Rate)
{
	return 0;
}

int USlotStatics::TakeItemToSlotArrayRateDelta(TArray<FSlotReference> Slots, FSlotReference Other, float Rate, float DeltaTime)
{
	return 0;
}

bool USlotStatics::SlotArrayHasAnyItem(TArray<FSlotReference> Slots)
{
	return false;
}

bool USlotStatics::SlotArrayGetItem(TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, int Amount)
{
	return false;
}

APhysicalItem* USlotStatics::SlotArrayGetSlottedItemThatCanAcceptChangeInAmountForItemType(TArray<FSlotReference> itemSlots, TSubclassOf<UItemType> itemType, bool changeIsPositive)
{
	return nullptr;
}

bool USlotStatics::SlotArrayHasItem(TArray<FSlotReference> Slots, TSubclassOf<UItemType> itemType)
{
	return false;
}

FSlotReference USlotStatics::SlotArraySlotWithItem(TArray<FSlotReference> Slots, TSubclassOf<UItemType> itemType)
{
	return FSlotReference();
}

FSlotReference USlotStatics::SlotArraySlotWithAnyItem(TArray<FSlotReference> Slots)
{
	return FSlotReference();
}

FSlotReference USlotStatics::SlotArrayEmptySlot(TArray<FSlotReference> Slots)
{
	return FSlotReference();
}

FSlotReference USlotStatics::SlotArraySlotForItem(TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type)
{
	return FSlotReference();
}

FSlotReference USlotStatics::SlotArraySlotForPhysicalItem(TArray<FSlotReference> Slots, APhysicalItem* physicalItem)
{
	return FSlotReference();
}

FSlotReference USlotStatics::SlotArrayQueryBestEmptySlot(TArray<FSlotReference> Slots, UClickQuery* Query)
{
	return FSlotReference();
}

FSlotReference USlotStatics::SlotArrayQueryBestFullSlot(TArray<FSlotReference> Slots, UClickQuery* Query)
{
	return FSlotReference();
}

FSlotReference USlotStatics::SlotArrayQueryBestSlot(TArray<FSlotReference> Slots, UClickQuery* Query)
{
	return FSlotReference();
}

void USlotStatics::SlotArrayEnableClickable(TArray<FSlotReference> Slots, bool Clickable)
{

}

bool USlotStatics::SlotArrayGetAllSlottedItemsThatHaveType(TArray<FSlotReference> itemSlots, TArray<APhysicalItem *> outItemArray, TSubclassOf<UItemType> itemType)
{
	return false;
}

bool USlotStatics::SlotArrayGetAllSlottedItemsThatCanAcceptChangeInAmountForItemType(TArray<FSlotReference> itemSlots, TArray<APhysicalItem *> outItemArray, TSubclassOf<UItemType> itemType, bool changeIsPositive)
{
	return false;
}

int USlotStatics::SlotArrayGetNumberOfEmptyContainers(TArray<FSlotReference> itemSlots, TSubclassOf<UItemType> storageTypeContainersCouldAccept)
{
	return 0;
}

bool USlotStatics::SlotArrayGetAllSlottedItemsThatAreEmptyContainers(TArray<FSlotReference> itemSlots, TSubclassOf<UItemType> typeToCheckAgainstStorageWhitelist, TArray<APhysicalItem *> outEmptyContainerItems)
{
	return false;
}

int USlotStatics::SlotArrayGetNumberOfSlottedItemsThatHaveItemType(TArray<FSlotReference> itemSlots, TSubclassOf<UItemType> itemType)
{
	return 0;
}

int USlotStatics::AddItem(FSlotReference slotRef, TSubclassOf<UItemType> type, int amount, float ejectForce)
{
	return 0;
}

int USlotStatics::WillAddItem(FSlotReference slotRef, TSubclassOf<UItemType> type, int amount, float ejectForce)
{
	return 0;
}

int USlotStatics::AddItemRate(FSlotReference slotRef, TSubclassOf<UItemType> AddType, float Rate)
{
	return 0;
}

int USlotStatics::AddItemRateDelta(FSlotReference slotRef, TSubclassOf<UItemType> AddType, float Rate, float DeltaTime)
{
	return 0;
}

int USlotStatics::TakeAnyItem(FSlotReference Slot, TSubclassOf<UItemType> Type, int Amount)
{
	return 0;
}

int USlotStatics::TakeItem(FSlotReference slotRef, TSubclassOf<UItemType> Type, int Amount)
{
	return 0;
}

int USlotStatics::TakeItemRate(FSlotReference slotRef, TSubclassOf<UItemType> Type, float Rate)
{
	return 0;
}

int USlotStatics::TakeItemRateDelta(FSlotReference slotRef, TSubclassOf<UItemType> Type, float Rate, float DeltaTime)
{
	return 0;
}

int USlotStatics::TakeAnyItemRate(FSlotReference slotRef, TSubclassOf<UItemType> Type, float Rate)
{
	return 0;
}

int USlotStatics::TakeAnyItemRateDelta(FSlotReference slotRef, TSubclassOf<UItemType> Type, float Rate, float DeltaTime)
{
	return 0;
}

int USlotStatics::TakeSlotItem(FSlotReference slotRef, FSlotReference otherSlotRef, int Amount)
{
	return 0;
}

int USlotStatics::TakeSlotItemToComponent(UItemComponent* Component, FSlotReference Other, int Amount)
{
	return 0;
}

int USlotStatics::TakeSlotItemRate(FSlotReference slotRef, FSlotReference otherSlotRef, float Rate)
{
	return 0;
}

int USlotStatics::TakeSlotItemRateDelta(FSlotReference slotRef, FSlotReference otherSlotRef, float Rate, float DeltaTime)
{
	return 0;
}

int USlotStatics::TakeSlotItemRateToComponent(UItemComponent* Component, FSlotReference Other, float Rate)
{
	return 0;
}

int USlotStatics::TakeSlotItemRateDeltaToComponent(UItemComponent* Component, FSlotReference Other, float Rate, float DeltaTime)
{
	return 0;
}

int USlotStatics::TakeComponentItemToSlot(FSlotReference SlotRef, UItemComponent* OtherComponent, int Amount)
{
	return 0;
}

int USlotStatics::TakeComponentItemRateToSlot(FSlotReference SlotRef, UItemComponent* Other, float Rate)
{
	return 0;
}

int USlotStatics::TakeComponentItemRateDeltaToSlot(FSlotReference SlotRef, UItemComponent* Other, float Rate, float DeltaTime)
{
	return 0;
}

int USlotStatics::SlotItemAmount(FSlotReference slotRef, TSubclassOf<UItemType> Type)
{
	return 0;
}

bool USlotStatics::HasItem(FSlotReference slotRef, TSubclassOf<UItemType> Type)
{
	return false;
}

bool USlotStatics::HasFullResource(FSlotReference slotRef)
{
	return false;
}

int USlotStatics::GetItemAmount(FSlotReference SlotRef, TSubclassOf<UItemType> Type)
{
	return 0;
}

int USlotStatics::GetNumberOfDiscreteSlottedItems(FSlotReference SlotRef, TSubclassOf<UItemType> Type)
{
	return 0;
}

bool USlotStatics::GetAnyItem(FSlotReference SlotComponent, int Amount, TSubclassOf<UItemType> Type)
{
	return false;
}

bool USlotStatics::HasAnyItem(FSlotReference slotRef)
{
	return false;
}

bool USlotStatics::HasSpaceAvailableAtTier(FSlotReference SlotRef, int Tier, bool AsIndicator)
{
	return false;
}

bool USlotStatics::IsAPowerCableSlot(FSlotReference slotRef)
{
	return false;
}

int USlotStatics::FindFirstAvailableSubslot(FSlotReference SlotRef, int Tier, bool AsIndicator)
{
	return 0;
}

FTransform USlotStatics::GetSubslotTransform(FSlotReference SlotRef, int SubslotIndex)
{
	return FTransform();
}

bool USlotStatics::IsCompatibleWithType(FSlotReference SlotReference, TSubclassOf<UItemType> ItemType)
{
	return false;
}

TSubclassOf<UItemType> USlotStatics::GetItemTypeClass(FSlotReference SlotRef)
{
	return UItemType::StaticClass();
}

TSubclassOf<UItemType> USlotStatics::GetPrimaryItemTypeClass(FSlotReference SlotRef)
{
	return UItemType::StaticClass();
}

TSubclassOf<UItemType> USlotStatics::GetStoredSubItemTypeClass(FSlotReference SlotRef)
{
	return UItemType::StaticClass();
}

bool USlotStatics::AttemptToPlaceItemInConnectedStorageSlotNetwork(APhysicalItem* Item, AActor* ActorInStorageNetwork)
{
	return false;
}

bool USlotStatics::AttemptToPlacePrimaryItemInConnectedStorageSlotNetwork(FSlotReference SlotRef, AActor* ActorInStorageNetwork)
{
	return false;
}

bool USlotStatics::AttemptToFetchItemFromConnectedStorageSlotNetworkToSlotArray(TSubclassOf<UItemType> ItemToRetrieve, TArray<FSlotReference> Slots, AActor* ActorInStorageNetwork, EItemRetrievalQuantityFilter ItemRetrievalQuantityFilter, bool TakeAll)
{
	return false;
}

int USlotStatics::AttemptToFetchItemsFromConnectedStorageSlotNetworkToSlotArray(TSubclassOf<UItemType> ItemToRetrieve, TArray<FSlotReference> Slots, AActor* ActorInStorageNetwork, int NumToTake)
{
	return 0;
}

TArray<APhysicalItem *> USlotStatics::GetAllItemsInConnectedStorage(AActor* baseActor)
{
	TArray<APhysicalItem *> x;
	return x;
}

bool USlotStatics::MoveItemFromCurrentSlotToSlotArray(APhysicalItem* Item, TArray<FSlotReference> Slots)
{
	return false;
}

UTooltipComponent* USlotStatics::GetIndicatorTooltipForSlot(FSlotReference SlotRef, int SubslotIndex)
{
	return nullptr;
}

UTooltipComponent* USlotStatics::GetTooltipForSlot(FSlotReference SlotRef)
{
	return nullptr;
}

UItemType* USlotStatics::GetItemTypeCDO(FSlotReference SlotRef)
{
	return nullptr;
}

UItemType* USlotStatics::GetPrimaryItemTypeCDO(FSlotReference SlotRef)
{
	return nullptr;
}

UItemType* USlotStatics::GetStoredSubItemTypeCDO(FSlotReference SlotRef)
{
	return nullptr;
}

void USlotStatics::EjectAllItemsInSubslotAndChildSubslots(FSlotReference SlotRef, int SubslotIndex, bool newOwner, bool FromTool, float RandomForce)
{

}

UPrimitiveComponent* USlotStatics::GetVisualPrimitiveForIndicator(FSlotReference SlotRef, int SlotIndicatorIndex)
{
	return nullptr;
}

APhysicalItem* USlotStatics::CloneItemIntoSlot(APhysicalItem* ItemToClone, FSlotReference SlotToSpawnCloneIn)
{
	return nullptr;
}

bool USlotStatics::IsSlotAnAuxSlot(FSlotReference slotRef)
{
	return false;
}

FVector USlotStatics::GetSlotRangeLocation(FSlotReference slotRef)
{
	return FVector();
}