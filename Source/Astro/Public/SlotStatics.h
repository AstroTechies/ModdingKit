#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "SlotReference.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "EAuxSlotType.h"
#include "SlotStatics.generated.h"

class UPrimitiveComponent;
class AActor;
class UItemType;
class APhysicalItem;
class UItemComponent;
class UObject;
class UClickQuery;
class UTooltipComponent;
class UItemList;

UCLASS(Blueprintable)
class ASTRO_API USlotStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USlotStatics();
    UFUNCTION(BlueprintCallable)
    static bool WillTakePhysicalItemToSlotArray(const TArray<FSlotReference>& Slots, APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    static int32 WillAddItem(FSlotReference SlotRef, TSubclassOf<UItemType> Type, int32 Amount, float EjectForce);
    
    UFUNCTION(BlueprintCallable)
    static bool TakeToSlotArray(const TArray<FSlotReference>& Slots, FSlotReference Other);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeSlotItemToComponent(UItemComponent* Component, FSlotReference Other, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeSlotItemRateToComponent(UItemComponent* Component, FSlotReference Other, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeSlotItemRateDeltaToComponent(UItemComponent* Component, FSlotReference Other, float Rate, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeSlotItemRateDelta(FSlotReference Slot, FSlotReference Other, float Rate, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeSlotItemRate(FSlotReference Slot, FSlotReference Other, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeSlotItem(FSlotReference Slot, FSlotReference Other, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static bool TakeSlotArrayPhysicalItemOfTypeToSlotArray(const TArray<FSlotReference>& FromSlots, const TArray<FSlotReference>& ToSlots, TSubclassOf<UItemType> Type, const TArray<APhysicalItem*> IgnoredItems);
    
    UFUNCTION(BlueprintCallable)
    static bool TakePhysicalItemToSlotArray(const TArray<FSlotReference>& Slots, APhysicalItem* Item, bool FromTool);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemToSlotArrayRateDelta(const TArray<FSlotReference>& Slots, FSlotReference Other, float Rate, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemToSlotArrayRate(UObject* WorldContextObject, const TArray<FSlotReference>& Slots, FSlotReference Other, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemToSlotArray(const TArray<FSlotReference>& Slots, FSlotReference Other, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemRateDelta(FSlotReference Slot, TSubclassOf<UItemType> Type, float Rate, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemRate(FSlotReference Slot, TSubclassOf<UItemType> Type, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemFromSlotArrayRateDelta(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, float Rate, float DeltaTime, int32 Max);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemFromSlotArrayRate(UObject* WorldContextObject, const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, float Rate, int32 Max);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemFromSlotArray(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItem(FSlotReference Slot, TSubclassOf<UItemType> Type, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeComponentItemToSlot(FSlotReference SlotRef, UItemComponent* OtherComponent, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeComponentItemRateToSlot(FSlotReference SlotRef, UItemComponent* Other, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeComponentItemRateDeltaToSlot(FSlotReference SlotRef, UItemComponent* Other, float Rate, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeAnyItemRateDelta(FSlotReference Slot, TSubclassOf<UItemType>& Type, float Rate, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeAnyItemRate(FSlotReference Slot, TSubclassOf<UItemType>& Type, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeAnyItemFromSlotArrayRateDelta(const TArray<FSlotReference>& Slots, float Rate, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeAnyItemFromSlotArrayRate(UObject* WorldContextObject, const TArray<FSlotReference>& Slots, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeAnyItemFromSlotArray(const TArray<FSlotReference>& Slots, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeAnyItem(FSlotReference Slot, TSubclassOf<UItemType>& Type, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static bool SpawnItemsInSlotArray(const TArray<FSlotReference>& Slots, const TArray<TSubclassOf<UItemType>>& ItemsToSpawn, TArray<APhysicalItem*>& OutSpawnedItems, bool packageItem);
    
    UFUNCTION(BlueprintCallable)
    static int32 SlotItemAmount(FSlotReference Slot, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintPure)
    static FSlotReference SlotArraySlotWithItem(const TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintPure)
    static FSlotReference SlotArraySlotWithAnyItem(const TArray<FSlotReference> Slots);
    
    UFUNCTION(BlueprintPure)
    static FSlotReference SlotArraySlotForPhysicalItem(const TArray<FSlotReference> Slots, APhysicalItem* PhysicalItem);
    
    UFUNCTION(BlueprintPure)
    static FSlotReference SlotArraySlotForItem(const TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintPure)
    static FSlotReference SlotArrayQueryBestSlot(const TArray<FSlotReference> Slots, UClickQuery* Query);
    
    UFUNCTION(BlueprintPure)
    static FSlotReference SlotArrayQueryBestFullSlot(const TArray<FSlotReference> Slots, UClickQuery* Query);
    
    UFUNCTION(BlueprintPure)
    static FSlotReference SlotArrayQueryBestEmptySlot(const TArray<FSlotReference> Slots, UClickQuery* Query);
    
    UFUNCTION(BlueprintPure)
    static bool SlotArrayHasItem(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintPure)
    static bool SlotArrayHasAnyItem(const TArray<FSlotReference>& Slots);
    
    UFUNCTION(BlueprintCallable)
    static APhysicalItem* SlotArrayGetSlottedItemThatCanAcceptChangeInAmountForItemType(const TArray<FSlotReference>& itemSlots, TSubclassOf<UItemType> ItemType, bool changeIsPositive);
    
    UFUNCTION(BlueprintCallable)
    static int32 SlotArrayGetNumberOfSlottedItemsThatHaveItemType(const TArray<FSlotReference>& itemSlots, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintPure)
    static int32 SlotArrayGetNumberOfEmptyContainers(const TArray<FSlotReference>& itemSlots, TSubclassOf<UItemType> typeToCheckAgainstStorageWhitelist);
    
    UFUNCTION(BlueprintPure)
    static bool SlotArrayGetItem(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, int32& Amount);
    
    UFUNCTION(BlueprintCallable)
    static bool SlotArrayGetAllSlottedItemsThatHaveType(const TArray<FSlotReference>& itemSlots, TArray<APhysicalItem*>& outItemArray, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    static bool SlotArrayGetAllSlottedItemsThatCanAcceptChangeInAmountForItemType(const TArray<FSlotReference>& itemSlots, TArray<APhysicalItem*>& outItemArray, TSubclassOf<UItemType> ItemType, bool changeIsPositive);
    
    UFUNCTION(BlueprintCallable)
    static bool SlotArrayGetAllSlottedItemsThatAreEmptyContainers(const TArray<FSlotReference>& itemSlots, TSubclassOf<UItemType> typeToCheckAgainstStorageWhitelist, TArray<APhysicalItem*>& outEmptyContainerItems);
    
    UFUNCTION(BlueprintCallable)
    static bool SlotArrayGetAllSlottedItems(const TArray<FSlotReference>& itemSlots, TArray<APhysicalItem*>& outItemArray);
    
    UFUNCTION(BlueprintCallable)
    static void SlotArrayEnableClickable(const TArray<FSlotReference> Slots, bool clickable);
    
    UFUNCTION(BlueprintPure)
    static FSlotReference SlotArrayEmptySlot(const TArray<FSlotReference> Slots);
    
    UFUNCTION(BlueprintCallable)
    static int32 SlotArrayEmptyCount(const TArray<FSlotReference>& Slots);
    
    UFUNCTION(BlueprintCallable)
    static bool MoveItemFromCurrentSlotToSlotArray(APhysicalItem* Item, const TArray<FSlotReference>& Slots);
    
    UFUNCTION(BlueprintPure)
    static bool IsSlotAnAuxSlot(FSlotReference Slot);
    
    UFUNCTION(BlueprintPure)
    static bool IsCompatibleWithType(FSlotReference Slot, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintPure)
    static bool IsAPowerCableSlot(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintPure)
    static bool HasSpaceAvailableAtTier(FSlotReference SlotRef, int32 Tier, bool AsIndicator);
    
    UFUNCTION(BlueprintPure)
    static bool HasItem(FSlotReference Slot, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintPure)
    static bool HasFullResource(FSlotReference Slot);
    
    UFUNCTION(BlueprintPure)
    static bool HasAnyItem(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintPure)
    static UPrimitiveComponent* GetVisualPrimitiveForIndicator(const FSlotReference& SlotRef, int32 SlotIndicatorIndex);
    
    UFUNCTION(BlueprintPure)
    static UTooltipComponent* GetTooltipForSlot(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintPure)
    static FTransform GetSubslotTransform(FSlotReference SlotRef, int32 SubslotIndex);
    
    UFUNCTION(BlueprintPure)
    static TSubclassOf<UItemType> GetStoredSubItemTypeClass(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintPure)
    UItemType* GetStoredSubItemTypeCDO(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintPure)
    static FVector GetSlotRangeLocation(const FSlotReference& SlotRef);
    
    UFUNCTION(BlueprintPure)
    static TSubclassOf<UItemList> GetSlotItemFiltrationList(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintPure)
    static TSubclassOf<UItemType> GetPrimaryItemTypeClass(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintPure)
    UItemType* GetPrimaryItemTypeCDO(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintPure)
    static int32 GetNumberOfDiscreteSlottedItems(FSlotReference SlotRef, const TSubclassOf<UItemType>& Type);
    
    UFUNCTION(BlueprintPure)
    static TSubclassOf<UItemType> GetItemTypeClass(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintPure)
    UItemType* GetItemTypeCDO(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintPure)
    static int32 GetItemAmount(FSlotReference Slot, const TSubclassOf<UItemType>& Type);
    
    UFUNCTION(BlueprintPure)
    static UTooltipComponent* GetIndicatorTooltipForSlot(FSlotReference SlotRef, int32 SubslotIndex);
    
    UFUNCTION(BlueprintPure)
    static EAuxSlotType GetAuxSlotType(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintPure)
    static bool GetAnyItem(FSlotReference SlotRef, int32& Amount, TSubclassOf<UItemType>& Type);
    
    UFUNCTION(BlueprintCallable)
    static TArray<APhysicalItem*> GetAllItemsInConnectedStorage(AActor* baseActor);
    
    UFUNCTION(BlueprintPure)
    static int32 FindSubslotOfItem(FSlotReference SlotRef, APhysicalItem* Item);
    
    UFUNCTION(BlueprintPure)
    static int32 FindFirstAvailableSubslot(FSlotReference SlotRef, int32 Tier, bool AsIndicator);
    
    UFUNCTION(BlueprintCallable)
    static void EjectAllItemsInSubslotAndChildSubslots(FSlotReference SlotRef, int32 SubslotIndex, bool NewOwner, bool FromTool, float RandomForce);
    
    UFUNCTION(BlueprintCallable)
    static APhysicalItem* CloneItemIntoSlot(APhysicalItem* ItemToClone, FSlotReference SlotToSpawnCloneIn);
    
    UFUNCTION(BlueprintCallable)
    static bool AttemptToPlacePrimaryItemInConnectedStorageSlotNetwork(FSlotReference SlotRef, AActor* ActorInStorageNetwork);
    
    UFUNCTION(BlueprintCallable)
    static bool AttemptToPlaceItemInConnectedStorageSlotNetwork(APhysicalItem* Item, AActor* ActorInStorageNetwork);
    
    UFUNCTION(BlueprintCallable)
    static int32 AddToSlotArrayRateDelta(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, float Rate, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 AddToSlotArrayRate(UObject* WorldContextObject, const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 AddToSlotArray(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static int32 AddItemRateDelta(FSlotReference Slot, TSubclassOf<UItemType> Type, float Rate, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 AddItemRate(FSlotReference Slot, TSubclassOf<UItemType> Type, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 AddItem(FSlotReference SlotRef, TSubclassOf<UItemType> Type, int32 Amount, float EjectForce);
    
};

