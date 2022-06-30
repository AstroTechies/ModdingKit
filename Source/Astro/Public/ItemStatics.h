#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SlotReference.h"
#include "ESlottableItemsFiltrationListBehavior.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Recipe.h"
#include "ScannableStatus.h"
#include "EUseContext.h"
#include "ItemStatics.generated.h"

class APhysicalItem;
class UItemType;
class UObject;
class UItemList;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UItemStatics : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UItemStatics();
    UFUNCTION(BlueprintPure)
    static bool WillCraftItem(const TArray<FSlotReference> &InputSlots, FSlotReference outputSlot, const TArray<TSubclassOf<UItemType>> &ItemTypes);

    UFUNCTION(BlueprintCallable)
    static int32 TryCraftItemDelta(const TArray<FSlotReference> &InputSlots, FSlotReference outputSlot, const TArray<TSubclassOf<UItemType>> &ItemTypes, float Rate, float DeltaTime);

    UFUNCTION(BlueprintCallable)
    static int32 TryCraftItem(const TArray<FSlotReference> &InputSlots, FSlotReference outputSlot, const TArray<TSubclassOf<UItemType>> &ItemTypes, float Rate);

    UFUNCTION(BlueprintCallable)
    static APhysicalItem *SpawnDeployablePackagedItem(const UObject *WorldContextObject, TSubclassOf<APhysicalItem> PhysicalItemClassPackagedItemWillContain, FTransform SpawnTransform);

    UFUNCTION(BlueprintPure)
    static int32 SmallItemAmountDelta();

    UFUNCTION(BlueprintPure)
    static bool ResourcePassesFiltrationList(TSubclassOf<UItemType> ItemToTest, TSubclassOf<UItemList> FiltrationList, ESlottableItemsFiltrationListBehavior FiltrationBehavior);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static bool RemoveItemFromBundleAndPlaceOnGroundNearby(APhysicalItem *BundledItem, FVector OffsetForGroundUnbundling, bool bPretendAsIfInAuxSlot);

    UFUNCTION(BlueprintPure)
    static float RecipeFromAmount(int32 Amount);

    UFUNCTION(BlueprintPure)
    static UItemType *PhysicalItemTypeCDO(TSubclassOf<APhysicalItem> PhysicalItemClass);

    UFUNCTION(BlueprintCallable)
    static bool PhysicalItemResetItemStartingAmountAndCapacityToClassDefaults(APhysicalItem *PhysicalItem);

    UFUNCTION(BlueprintPure)
    static TSubclassOf<UItemType> PhysicalItemGetDefaultLiteralItemTypeClass(TSubclassOf<APhysicalItem> PhysicalItemClass);

    UFUNCTION(BlueprintPure)
    static APhysicalItem *PhysicalItemDefault(TSubclassOf<APhysicalItem> PhysicalItemClass);

    UFUNCTION(BlueprintPure)
    static FRecipe MakeItemRecipeFromSlots(const TArray<FSlotReference> &itemSlots);

    UFUNCTION(BlueprintPure)
    static FRecipe MakeItemRecipe(const TArray<TSubclassOf<UItemType>> &ItemTypes);

    UFUNCTION(BlueprintPure)
    static int32 ItemUnitAmount();

protected:
    UFUNCTION(BlueprintPure)
    static bool IsScannableStatusValid(FScannableStatus Status);

public:
    UFUNCTION(BlueprintPure)
    static bool IsRecipeValid(const FRecipe &Recipe);

    UFUNCTION(BlueprintPure)
    static bool IsPackageableItemType(TSubclassOf<UItemType> ItemType);

    UFUNCTION(BlueprintPure)
    static bool IsItemTypeOnlyStoredInContainers(TSubclassOf<UItemType> ItemType);

    UFUNCTION(BlueprintPure)
    static bool IsItemPartOfRecipe(const FRecipe &Recipe, TSubclassOf<UItemType> ItemType);

    UFUNCTION(BlueprintPure)
    static bool IsDeployablePackageItemType(TSubclassOf<UItemType> ItemType);

    UFUNCTION(BlueprintPure)
    static bool IsContainerItemType(TSubclassOf<UItemType> ItemType);

    UFUNCTION(BlueprintPure)
    static FText GetUseContextVerb(EUseContext Context);

    UFUNCTION(BlueprintPure)
    static TSubclassOf<APhysicalItem> GetPackageTypeForItem(APhysicalItem *ItemToPackage);

    UFUNCTION(BlueprintPure)
    static FText GetExamineVerb();

    UFUNCTION(BlueprintPure)
    static FText GetCraftingSourcesTooltipDescription(TSubclassOf<UItemType> Item);

    UFUNCTION(BlueprintPure)
    static TSubclassOf<UItemType> FindRecipeTarget(const FRecipe &Recipe, const TArray<TSubclassOf<UItemType>> &ItemTypes);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void DestroyItemAndAllSlottedItemsRecursively(APhysicalItem *ItemToDestroy);

    UFUNCTION(BlueprintPure)
    static int32 ConvertDeformationDeltaToSedimentAmount(float deformationDelta, float SedimentDeformationRatio);

    UFUNCTION(BlueprintCallable)
    static bool CanSwapHeldItemWithSlottedItem(const APhysicalItem *HeldItem, const APhysicalItem *SlottedItem);

    UFUNCTION(BlueprintCallable)
    static bool CanHeldItemInteractWithTargetItem(const APhysicalItem *HeldItem, const APhysicalItem *hitItem, bool &outHighlightChildrenOfTarget);

    UFUNCTION(BlueprintPure)
    static int32 AmountFromRecipe(float Amount);

    UFUNCTION(BlueprintPure)
    static int32 AmountFromRate(float Rate, float DeltaSeconds);
};
