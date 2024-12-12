#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EAuxSlotType.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "SlotStatics.generated.h"

class AActor;
class APhysicalItem;
class UClickQuery;
class UItemComponent;
class UItemList;
class UItemType;
class UObject;
class UPrimitiveComponent;
class UTooltipComponent;

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
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static int32 TakeItemToSlotArrayRate(UObject* WorldContextObject, const TArray<FSlotReference>& Slots, FSlotReference Other, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemToSlotArray(const TArray<FSlotReference>& Slots, FSlotReference Other, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemRateDelta(FSlotReference Slot, TSubclassOf<UItemType> Type, float Rate, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemRate(FSlotReference Slot, TSubclassOf<UItemType> Type, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeItemFromSlotArrayRateDelta(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type, float Rate, float DeltaTime, int32 Max);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
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
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static int32 TakeAnyItemFromSlotArrayRate(UObject* WorldContextObject, const TArray<FSlotReference>& Slots, float Rate);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeAnyItemFromSlotArray(const TArray<FSlotReference>& Slots, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static int32 TakeAnyItem(FSlotReference Slot, TSubclassOf<UItemType>& Type, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static bool SpawnItemsInSlotArray(const TArray<FSlotReference>& Slots, const TArray<TSubclassOf<UItemType>>& ItemsToSpawn, TArray<APhysicalItem*>& OutSpawnedItems, bool packageItem);
    
    UFUNCTION(BlueprintCallable)
    static int32 SlotItemAmount(FSlotReference Slot, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlotReference SlotArraySlotWithItem(const TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlotReference SlotArraySlotWithAnyItem(const TArray<FSlotReference> Slots);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlotReference SlotArraySlotForPhysicalItem(const TArray<FSlotReference> Slots, APhysicalItem* PhysicalItem);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlotReference SlotArraySlotForItem(const TArray<FSlotReference> Slots, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlotReference SlotArrayQueryBestSlot(const TArray<FSlotReference> Slots, UClickQuery* Query);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlotReference SlotArrayQueryBestFullSlot(const TArray<FSlotReference> Slots, UClickQuery* Query);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlotReference SlotArrayQueryBestEmptySlot(const TArray<FSlotReference> Slots, UClickQuery* Query);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SlotArrayHasItem(const TArray<FSlotReference>& Slots, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SlotArrayHasAnyItem(const TArray<FSlotReference>& Slots);
    
    UFUNCTION(BlueprintCallable)
    static APhysicalItem* SlotArrayGetSlottedItemThatCanAcceptChangeInAmountForItemType(const TArray<FSlotReference>& itemSlots, TSubclassOf<UItemType> ItemType, bool changeIsPositive);
    
    UFUNCTION(BlueprintCallable)
    static int32 SlotArrayGetNumberOfSlottedItemsThatHaveItemType(const TArray<FSlotReference>& itemSlots, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 SlotArrayGetNumberOfEmptyContainers(const TArray<FSlotReference>& itemSlots, TSubclassOf<UItemType> typeToCheckAgainstStorageWhitelist);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
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
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlotReference SlotArrayEmptySlot(const TArray<FSlotReference> Slots);
    
    UFUNCTION(BlueprintCallable)
    static int32 SlotArrayEmptyCount(const TArray<FSlotReference>& Slots);
    
    UFUNCTION(BlueprintCallable)
    static bool MoveItemFromCurrentSlotToSlotArray(APhysicalItem* Item, const TArray<FSlotReference>& Slots);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSlotAnAuxSlot(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsCompatibleWithType(FSlotReference Slot, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAPowerCableSlot(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasSpaceAvailableAtTier(FSlotReference SlotRef, int32 Tier, bool AsIndicator);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasItem(FSlotReference Slot, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasFullResource(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasAnyItem(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UPrimitiveComponent* GetVisualPrimitiveForIndicator(const FSlotReference& SlotRef, int32 SlotIndicatorIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UTooltipComponent* GetTooltipForSlot(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTransform GetSubslotTransform(FSlotReference SlotRef, int32 SubslotIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<UItemType> GetStoredSubItemTypeClass(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemType* GetStoredSubItemTypeCDO(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetSlotRangeLocation(const FSlotReference& SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<UItemList> GetSlotItemFiltrationList(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<UItemType> GetPrimaryItemTypeClass(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemType* GetPrimaryItemTypeCDO(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetNumberOfDiscreteSlottedItems(FSlotReference SlotRef, const TSubclassOf<UItemType>& Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<UItemType> GetItemTypeClass(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemType* GetItemTypeCDO(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetItemAmount(FSlotReference Slot, const TSubclassOf<UItemType>& Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UTooltipComponent* GetIndicatorTooltipForSlot(FSlotReference SlotRef, int32 SubslotIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EAuxSlotType GetAuxSlotType(FSlotReference SlotRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetAnyItem(FSlotReference SlotRef, int32& Amount, TSubclassOf<UItemType>& Type);
    
    UFUNCTION(BlueprintCallable)
    static TArray<APhysicalItem*> GetAllItemsInConnectedStorage(AActor* baseActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 FindSubslotOfItem(FSlotReference SlotRef, APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
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
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
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

