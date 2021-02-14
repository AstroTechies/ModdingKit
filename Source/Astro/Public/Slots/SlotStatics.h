// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Slots/SlotReference.h"
#include "Items/ItemType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SlotStatics.generated.h"

class UClickQuery;
class APhysicalItem;

UENUM(BlueprintType)
enum class EItemRetrievalQuantityFilter : uint8 {
	OnlyFullItem = 0,
	OnlyPartialItem = 1,
	FullOrPartialItem = 2
};

UCLASS()
class ASTRO_API USlotStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		static bool SpawnItemsInSlotArray(TArray<FSlotReference> slots, TArray<TSubclassOf<UItemType>> itemsToSpawn, TArray<APhysicalItem *> outSpawnedItems);
	UFUNCTION(BlueprintCallable)
		static int SlotArrayEmptyCount(TArray<FSlotReference> Slots);
	UFUNCTION(BlueprintCallable)
		static int AddToSlotArray(TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, int Amount);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static int AddToSlotArrayRate(UObject* WorldContextObject, TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, float Rate);
	UFUNCTION(BlueprintCallable)
		static int AddToSlotArrayRateDelta(TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, float Rate, float DeltaTime);
	UFUNCTION(BlueprintCallable)
		static bool TakeToSlotArray(TArray<FSlotReference> Slots, FSlotReference Other);
	UFUNCTION(BlueprintCallable)
		static int TakeItemFromSlotArray(TArray<FSlotReference> Slots, TSubclassOf<UItemType> ItemType, int Amount);
	UFUNCTION(BlueprintCallable)
		static int TakeAnyItemFromSlotArray(TArray<FSlotReference> Slots, int Amount);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static int TakeItemFromSlotArrayRate(UObject* WorldContextObject, TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, float Rate, int Max);
	UFUNCTION(BlueprintCallable)
		static int TakeItemFromSlotArrayRateDelta(TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, float Rate, float DeltaTime, int Max);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static int TakeAnyItemFromSlotArrayRate(UObject* WorldContextObject, TArray<FSlotReference> Slots, float Rate);
	UFUNCTION(BlueprintCallable)
		static int TakeAnyItemFromSlotArrayRateDelta(TArray<FSlotReference> Slots, float Rate, float DeltaTime);
	UFUNCTION(BlueprintCallable)
		static int TakeItemToSlotArray(TArray<FSlotReference> Slots, FSlotReference Other, int Amount);
	UFUNCTION(BlueprintCallable)
		static bool TakePhysicalItemToSlotArray(TArray<FSlotReference> Slots, APhysicalItem* Item, bool FromTool);
	UFUNCTION(BlueprintCallable)
		static bool TakeSlotArrayPhysicalItemOfTypeToSlotArray(TArray<FSlotReference> FromSlots, TArray<FSlotReference> ToSlots, TSubclassOf<UItemType> Type, TArray<APhysicalItem *> IgnoredItems);
	UFUNCTION(BlueprintCallable)
		static bool WillTakePhysicalItemToSlotArray(TArray<FSlotReference> Slots, APhysicalItem* Item);
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static int TakeItemToSlotArrayRate(UObject* WorldContextObject, TArray<FSlotReference> Slots, FSlotReference Other, float Rate);
	UFUNCTION(BlueprintCallable)
		static int TakeItemToSlotArrayRateDelta(TArray<FSlotReference> Slots, FSlotReference Other, float Rate, float DeltaTime);
	UFUNCTION(BlueprintCallable)
		static bool SlotArrayHasAnyItem(TArray<FSlotReference> Slots);
	UFUNCTION(BlueprintCallable)
		static bool SlotArrayGetItem(TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type, int Amount);
	UFUNCTION(BlueprintCallable)
		static APhysicalItem* SlotArrayGetSlottedItemThatCanAcceptChangeInAmountForItemType(TArray<FSlotReference> itemSlots, TSubclassOf<UItemType> itemType, bool changeIsPositive);
	UFUNCTION(BlueprintCallable)
		static bool SlotArrayHasItem(TArray<FSlotReference> Slots, TSubclassOf<UItemType> itemType);
	UFUNCTION(BlueprintCallable)
		static FSlotReference SlotArraySlotWithItem(TArray<FSlotReference> Slots, TSubclassOf<UItemType> itemType);
	UFUNCTION(BlueprintCallable)
		static FSlotReference SlotArraySlotWithAnyItem(TArray<FSlotReference> Slots);
	UFUNCTION(BlueprintCallable)
		static FSlotReference SlotArrayEmptySlot(TArray<FSlotReference> Slots);
	UFUNCTION(BlueprintCallable)
		static FSlotReference SlotArraySlotForItem(TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type);
	UFUNCTION(BlueprintCallable)
		static FSlotReference SlotArraySlotForPhysicalItem(TArray<FSlotReference> Slots, APhysicalItem* physicalItem);
	UFUNCTION(BlueprintCallable)
		static FSlotReference SlotArrayQueryBestEmptySlot(TArray<FSlotReference> Slots, UClickQuery* Query);
	UFUNCTION(BlueprintCallable)
		static FSlotReference SlotArrayQueryBestFullSlot(TArray<FSlotReference> Slots, UClickQuery* Query);
	UFUNCTION(BlueprintCallable)
		static FSlotReference SlotArrayQueryBestSlot(TArray<FSlotReference> Slots, UClickQuery* Query);
	UFUNCTION(BlueprintCallable)
		static void SlotArrayEnableClickable(TArray<FSlotReference> Slots, bool Clickable);
	UFUNCTION(BlueprintCallable)
		static bool SlotArrayGetAllSlottedItemsThatHaveType(TArray<FSlotReference> itemSlots, TArray<APhysicalItem *> outItemArray, TSubclassOf<UItemType> itemType);
	UFUNCTION(BlueprintCallable)
		static bool SlotArrayGetAllSlottedItemsThatCanAcceptChangeInAmountForItemType(TArray<FSlotReference> itemSlots, TArray<APhysicalItem *> outItemArray, TSubclassOf<UItemType> itemType, bool changeIsPositive);
	UFUNCTION(BlueprintCallable)
		static int SlotArrayGetNumberOfEmptyContainers(TArray<FSlotReference> itemSlots, TSubclassOf<UItemType> storageTypeContainersCouldAccept);
	UFUNCTION(BlueprintCallable)
		static bool SlotArrayGetAllSlottedItemsThatAreEmptyContainers(TArray<FSlotReference> itemSlots, TSubclassOf<UItemType> typeToCheckAgainstStorageWhitelist, TArray<APhysicalItem *> outEmptyContainerItems);
	UFUNCTION(BlueprintCallable)
		static int SlotArrayGetNumberOfSlottedItemsThatHaveItemType(TArray<FSlotReference> itemSlots, TSubclassOf<UItemType> itemType);
	UFUNCTION(BlueprintCallable)
		static int AddItem(FSlotReference slotRef, TSubclassOf<UItemType> type, int amount, float ejectForce);
	UFUNCTION(BlueprintCallable)
		static int WillAddItem(FSlotReference slotRef, TSubclassOf<UItemType> type, int amount, float ejectForce);
	UFUNCTION(BlueprintCallable)
		static int AddItemRate(FSlotReference slotRef, TSubclassOf<UItemType> AddType, float Rate);
	UFUNCTION(BlueprintCallable)
		static int AddItemRateDelta(FSlotReference slotRef, TSubclassOf<UItemType> AddType, float Rate, float DeltaTime);
	UFUNCTION(BlueprintCallable)
		static int TakeAnyItem(FSlotReference Slot, TSubclassOf<UItemType> Type, int Amount);
	UFUNCTION(BlueprintCallable)
		static int TakeItem(FSlotReference slotRef, TSubclassOf<UItemType> Type, int Amount);
	UFUNCTION(BlueprintCallable)
		static int TakeItemRate(FSlotReference slotRef, TSubclassOf<UItemType> Type, float Rate);
	UFUNCTION(BlueprintCallable)
		static int TakeItemRateDelta(FSlotReference slotRef, TSubclassOf<UItemType> Type, float Rate, float DeltaTime);
	UFUNCTION(BlueprintCallable)
		static int TakeAnyItemRate(FSlotReference slotRef, TSubclassOf<UItemType> Type, float Rate);
	UFUNCTION(BlueprintCallable)
		static int TakeAnyItemRateDelta(FSlotReference slotRef, TSubclassOf<UItemType> Type, float Rate, float DeltaTime);
	UFUNCTION(BlueprintCallable)
		static int TakeSlotItem(FSlotReference slotRef, FSlotReference otherSlotRef, int Amount);
	UFUNCTION(BlueprintCallable)
		static int TakeSlotItemToComponent(UItemComponent* Component, FSlotReference Other, int Amount);
	UFUNCTION(BlueprintCallable)
		static int TakeSlotItemRate(FSlotReference slotRef, FSlotReference otherSlotRef, float Rate);
	UFUNCTION(BlueprintCallable)
		static int TakeSlotItemRateDelta(FSlotReference slotRef, FSlotReference otherSlotRef, float Rate, float DeltaTime);
	UFUNCTION(BlueprintCallable)
		static int TakeSlotItemRateToComponent(UItemComponent* Component, FSlotReference Other, float Rate);
	UFUNCTION(BlueprintCallable)
		static int TakeSlotItemRateDeltaToComponent(UItemComponent* Component, FSlotReference Other, float Rate, float DeltaTime);
	UFUNCTION(BlueprintCallable)
		static int TakeComponentItemToSlot(FSlotReference SlotRef, UItemComponent* OtherComponent, int Amount);
	UFUNCTION(BlueprintCallable)
		static int TakeComponentItemRateToSlot(FSlotReference SlotRef, UItemComponent* Other, float Rate);
	UFUNCTION(BlueprintCallable)
		static int TakeComponentItemRateDeltaToSlot(FSlotReference SlotRef, UItemComponent* Other, float Rate, float DeltaTime);
	UFUNCTION(BlueprintCallable)
		static int SlotItemAmount(FSlotReference slotRef, TSubclassOf<UItemType> Type);
	UFUNCTION(BlueprintCallable)
		static bool HasItem(FSlotReference slotRef, TSubclassOf<UItemType> Type);
	UFUNCTION(BlueprintCallable)
		static bool HasFullResource(FSlotReference slotRef);
	UFUNCTION(BlueprintCallable)
		static int GetItemAmount(FSlotReference SlotRef, TSubclassOf<UItemType> Type);
	UFUNCTION(BlueprintCallable)
		static int GetNumberOfDiscreteSlottedItems(FSlotReference SlotRef, TSubclassOf<UItemType> Type);
	UFUNCTION(BlueprintCallable)
		static bool GetAnyItem(FSlotReference SlotComponent, int Amount, TSubclassOf<UItemType> Type);
	UFUNCTION(BlueprintCallable)
		static bool HasAnyItem(FSlotReference slotRef);
	UFUNCTION(BlueprintCallable)
		static bool HasSpaceAvailableAtTier(FSlotReference SlotRef, int Tier, bool AsIndicator);
	UFUNCTION(BlueprintCallable)
		static bool IsAPowerCableSlot(FSlotReference slotRef);
	UFUNCTION(BlueprintCallable)
		static int FindFirstAvailableSubslot(FSlotReference SlotRef, int Tier, bool AsIndicator);
	UFUNCTION(BlueprintCallable)
		static FTransform GetSubslotTransform(FSlotReference SlotRef, int SubslotIndex);
	UFUNCTION(BlueprintCallable)
		static bool IsCompatibleWithType(FSlotReference SlotReference, TSubclassOf<UItemType> ItemType);
	UFUNCTION(BlueprintCallable)
		static TSubclassOf<UItemType> GetItemTypeClass(FSlotReference SlotRef);
	UFUNCTION(BlueprintCallable)
		static TSubclassOf<UItemType> GetPrimaryItemTypeClass(FSlotReference SlotRef);
	UFUNCTION(BlueprintCallable)
		static TSubclassOf<UItemType> GetStoredSubItemTypeClass(FSlotReference SlotRef);
	UFUNCTION(BlueprintCallable)
		static bool AttemptToPlaceItemInConnectedStorageSlotNetwork(APhysicalItem* Item, AActor* ActorInStorageNetwork);
	UFUNCTION(BlueprintCallable)
		static bool AttemptToPlacePrimaryItemInConnectedStorageSlotNetwork(FSlotReference SlotRef, AActor* ActorInStorageNetwork);
	UFUNCTION(BlueprintCallable)
		static bool AttemptToFetchItemFromConnectedStorageSlotNetworkToSlotArray(TSubclassOf<UItemType> ItemToRetrieve, TArray<FSlotReference> Slots, AActor* ActorInStorageNetwork, EItemRetrievalQuantityFilter ItemRetrievalQuantityFilter, bool TakeAll);
	UFUNCTION(BlueprintCallable)
		static int AttemptToFetchItemsFromConnectedStorageSlotNetworkToSlotArray(TSubclassOf<UItemType> ItemToRetrieve, TArray<FSlotReference> Slots, AActor* ActorInStorageNetwork, int NumToTake);
	UFUNCTION(BlueprintCallable)
		static TArray<APhysicalItem *> GetAllItemsInConnectedStorage(AActor* baseActor);
	UFUNCTION(BlueprintCallable)
		static bool MoveItemFromCurrentSlotToSlotArray(APhysicalItem* Item, TArray<FSlotReference> Slots);
	UFUNCTION(BlueprintCallable)
		static UTooltipComponent* GetIndicatorTooltipForSlot(FSlotReference SlotRef, int SubslotIndex);
	UFUNCTION(BlueprintCallable)
		static UTooltipComponent* GetTooltipForSlot(FSlotReference SlotRef);
	UFUNCTION(BlueprintCallable)
		static UItemType* GetItemTypeCDO(FSlotReference SlotRef);
	UFUNCTION(BlueprintCallable)
		static UItemType* GetPrimaryItemTypeCDO(FSlotReference SlotRef);
	UFUNCTION(BlueprintCallable)
		static UItemType* GetStoredSubItemTypeCDO(FSlotReference SlotRef);
	UFUNCTION(BlueprintCallable)
		static void EjectAllItemsInSubslotAndChildSubslots(FSlotReference SlotRef, int SubslotIndex, bool newOwner, bool FromTool, float RandomForce);
	UFUNCTION(BlueprintCallable)
		static UPrimitiveComponent* GetVisualPrimitiveForIndicator(FSlotReference SlotRef, int SlotIndicatorIndex);
	UFUNCTION(BlueprintCallable)
		static APhysicalItem* CloneItemIntoSlot(APhysicalItem* ItemToClone, FSlotReference SlotToSpawnCloneIn);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsSlotAnAuxSlot(FSlotReference slotRef);
	UFUNCTION(BlueprintCallable)
		static FVector GetSlotRangeLocation(FSlotReference slotRef);
};
