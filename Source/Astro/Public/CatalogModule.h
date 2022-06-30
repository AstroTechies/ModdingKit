#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ControlPanel.h"
#include "OnActiveCatalogEntryChangedDelegate.h"
#include "EItemVariantType.h"
#include "ESelectedItemUnlockState.h"
#include "CatalogModule.generated.h"

class UTooltipComponent;
class UItemType;
class UItemCatalog;
class UItemCatalogEntryDisplay;
class UItemCatalogCategoryDefinition;

UCLASS(Blueprintable, Abstract)
class ASTRO_API ACatalogModule : public AControlPanel
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable)
    FOnActiveCatalogEntryChanged OnActiveCatalogEntryChanged;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    UItemCatalog *ItemCatalog;

    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<UItemCatalogEntryDisplay>> CatalogEntryDisplayTypes;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    TArray<UItemCatalogEntryDisplay *> CatalogEntryDisplays;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    int32 ActiveCatalogEntryDisplayIndex;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    UItemCatalogCategoryDefinition *ActiveCatalogCategory;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    int32 ActiveCatalogEntryIndex;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float MaximumCatalogEntryScrollSpeed;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    EItemVariantType ActiveItemTypeVariantType;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    int32 ActiveVariantItemTypeIndex;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float MaximumVariantItemTypeScrollSpeed;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemType> DefaultSelectedItemType;

    UPROPERTY()
    TArray<UItemCatalogCategoryDefinition *> CategoryScrollOrder;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UTooltipComponent *TooltipComponent;

    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    uint8 IsCreativeCatalog : 1;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    UItemCatalogCategoryDefinition *AllCatalogItemsCategory;

public:
    ACatalogModule();
    UFUNCTION()
    void UnlockedItemsChanged(const TArray<TSubclassOf<UItemType>> &NewUnlockedItems);

    UFUNCTION(BlueprintCallable)
    bool TrySelectItemType(const TSubclassOf<UItemType> &ItemTypeToSelect);

    UFUNCTION(BlueprintCallable)
    void SetCategoryScrollList(const TArray<UItemCatalogCategoryDefinition *> &categoryList);

    UFUNCTION(BlueprintCallable)
    bool SetActiveCatalogCategory(const UItemCatalogCategoryDefinition *CategoryDefinition);

    UFUNCTION(BlueprintCallable)
    void ScrollVariants(int32 NumVariantsToScroll);

    UFUNCTION(BlueprintCallable)
    void ScrollToVariant(int32 VariantIndex, EItemVariantType VariantType);

    UFUNCTION(BlueprintCallable)
    void ScrollEntries(int32 NumEntriesToScroll);

    UFUNCTION()
    void ResearchPointBalanceChanged(float NewResearchPointBalance);

    UFUNCTION(BlueprintImplementableEvent)
    void OnUnlockedItemsChanged(const TArray<TSubclassOf<UItemType>> &NewUnlockedItems);

protected:
    UFUNCTION()
    void OnTooltipOverrideChanged();

    UFUNCTION(BlueprintImplementableEvent)
    void OnSelectedItemTypeChanged(const UItemType *selectedItemType, bool bImmediate);

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnResearchPointBalanceChanged(float NewResearchPointBalance);

    UFUNCTION()
    void OnCreativeModeCatalogUnlockedChanged();

protected:
    UFUNCTION()
    void OnCategoryRight();

    UFUNCTION()
    void OnCategoryLeft();

public:
    UFUNCTION()
    void KnownItemsChanged(const TArray<TSubclassOf<UItemType>> &newKnownItems);

    UFUNCTION(BlueprintPure)
    ESelectedItemUnlockState GetSelectedItemUnlockState() const;

    UFUNCTION(BlueprintPure)
    UItemType *GetSelectedItemType() const;

    UFUNCTION(BlueprintPure)
    UClass *GetSelectedItemPickupClass();

    UFUNCTION(BlueprintCallable)
    void ApplyPendingDisplayChanges();
};
