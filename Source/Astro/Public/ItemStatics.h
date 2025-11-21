#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ESlottableItemsFiltrationListBehavior.h"
#include "EUseContext.h"
#include "Recipe.h"
#include "ScannableStatus.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "ItemStatics.generated.h"

class APhysicalItem;
class UCraftingDependencyMapList;
class UItemList;
class UItemType;
class UObject;

UCLASS(Blueprintable)
class ASTRO_API UItemStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UItemStatics();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool WillCraftItem(const TArray<FSlotReference>& InputSlots, FSlotReference OutputSlot, const TArray<TSubclassOf<UItemType>>& itemTypes);
    
    UFUNCTION(BlueprintCallable)
    static int32 TryCraftItemDelta(const TArray<FSlotReference>& InputSlots, FSlotReference OutputSlot, const TArray<TSubclassOf<UItemType>>& itemTypes, float Rate, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 TryCraftItem(const TArray<FSlotReference>& InputSlots, FSlotReference OutputSlot, const TArray<TSubclassOf<UItemType>>& itemTypes, float Rate);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static APhysicalItem* SpawnDeployablePackagedItem(const UObject* WorldContextObject, TSubclassOf<APhysicalItem> PhysicalItemClassPackagedItemWillContain, FTransform SpawnTransform);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 SmallItemAmountDelta();
    
    UFUNCTION(BlueprintCallable)
    static int32 RestorePartialNuggetsForItem(APhysicalItem* inItem, const TSubclassOf<UItemType> inItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ResourcePassesFiltrationList(TSubclassOf<UItemType> ItemToTest, TSubclassOf<UItemList> FiltrationList, ESlottableItemsFiltrationListBehavior FiltrationBehavior);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static bool RemoveItemFromBundleAndPlaceOnGroundNearby(APhysicalItem* BundledItem, FVector OffsetForGroundUnbundling, bool bPretendAsIfInAuxSlot);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static APhysicalItem* RemoveItemFromBundle(APhysicalItem* BundledItem, FVector OffsetForGroundUnbundling, bool bPretendAsIfInAuxSlot, bool bRequireTraceHit);
    
    UFUNCTION(BlueprintCallable)
    static bool RefundNuggetsForItem(APhysicalItem* inItem, const TSubclassOf<UItemType> inItemType, const int32 inAmountToRefund, int32& outRemaining);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float RecipeFromAmount(int32 Amount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UItemType* PhysicalItemTypeCDO(TSubclassOf<APhysicalItem> PhysicalItemClass);
    
    UFUNCTION(BlueprintCallable)
    static bool PhysicalItemResetItemStartingAmountAndCapacityToClassDefaults(APhysicalItem* PhysicalItem);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<UItemType> PhysicalItemGetDefaultLiteralItemTypeClass(TSubclassOf<APhysicalItem> PhysicalItemClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static APhysicalItem* PhysicalItemDefault(TSubclassOf<APhysicalItem> PhysicalItemClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRecipe MakeItemRecipeFromSlots(const TArray<FSlotReference>& itemSlots);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRecipe MakeItemRecipe(const TArray<TSubclassOf<UItemType>>& itemTypes);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 ItemUnitAmount();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsScannableStatusValid(FScannableStatus Status);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsRecipeValid(const FRecipe& Recipe);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPackageableItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsItemTypeOnlyStoredInContainers(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsItemPartOfRecipe(const FRecipe& Recipe, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDeployablePackageItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsContainerItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText GetUseContextVerb(EUseContext Context);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<APhysicalItem> GetPackageTypeForItem(APhysicalItem* ItemToPackage);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText GetExamineVerb();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText GetCraftingSourcesTooltipDescription(TSubclassOf<UItemType> Item, UCraftingDependencyMapList* CraftingSources);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<UItemType> FindRecipeTarget(const FRecipe& Recipe, const TArray<TSubclassOf<UItemType>>& itemTypes);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void DestroyItemAndAllSlottedItemsRecursively(APhysicalItem* ItemToDestroy);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 ConvertDeformationDeltaToSedimentAmount(float deformationDelta, float SedimentDeformationRatio);
    
    UFUNCTION(BlueprintCallable)
    static bool CanSwapHeldItemWithSlottedItem(const APhysicalItem* HeldItem, const APhysicalItem* slottedItem);
    
    UFUNCTION(BlueprintCallable)
    static bool CanHeldItemInteractWithTargetItem(const APhysicalItem* HeldItem, const APhysicalItem* hitItem, bool& outHighlightChildrenOfTarget);
    
    UFUNCTION(BlueprintCallable)
    static void AnalyticsRecordItemCraftedEvent(const APhysicalItem* craftedItem);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 AmountFromRecipe(float Amount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 AmountFromRate(float Rate, float DeltaSeconds);
    
};

