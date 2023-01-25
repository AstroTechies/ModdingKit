#pragma once
#include "CoreMinimal.h"
#include "ControlPanel.h"
#include "EItemVariantType.h"
#include "ESelectedItemUnlockState.h"
#include "OnActiveCatalogEntryChangedDelegate.h"
#include "Templates/SubclassOf.h"
#include "CatalogModule.generated.h"

class UItemCatalog;
class UItemCatalogCategoryDefinition;
class UItemCatalogEntryDisplay;
class UItemType;
class UTooltipComponent;

UCLASS(Abstract, Blueprintable)
class ASTRO_API ACatalogModule : public AControlPanel {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActiveCatalogEntryChanged OnActiveCatalogEntryChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UItemCatalog* ItemCatalog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemCatalogEntryDisplay>> CatalogEntryDisplayTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UItemCatalogEntryDisplay*> CatalogEntryDisplays;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActiveCatalogEntryDisplayIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UItemCatalogCategoryDefinition* ActiveCatalogCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 ActiveCatalogEntryIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumCatalogEntryScrollSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EItemVariantType ActiveItemTypeVariantType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 ActiveVariantItemTypeIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumVariantItemTypeScrollSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> DefaultSelectedItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemCatalogCategoryDefinition*> CategoryScrollOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTooltipComponent* TooltipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 IsCreativeCatalog: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemCatalogCategoryDefinition* AllCatalogItemsCategory;
    
public:
    ACatalogModule();
    UFUNCTION(BlueprintCallable)
    void UnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItems);
    
    UFUNCTION(BlueprintCallable)
    bool TrySelectItemType(const TSubclassOf<UItemType>& ItemTypeToSelect);
    
    UFUNCTION(BlueprintCallable)
    void SetCategoryScrollList(const TArray<UItemCatalogCategoryDefinition*>& categoryList);
    
    UFUNCTION(BlueprintCallable)
    bool SetActiveCatalogCategory(const UItemCatalogCategoryDefinition* CategoryDefinition);
    
    UFUNCTION(BlueprintCallable)
    void ScrollVariants(int32 NumVariantsToScroll);
    
    UFUNCTION(BlueprintCallable)
    void ScrollToVariant(int32 VariantIndex, EItemVariantType VariantType);
    
    UFUNCTION(BlueprintCallable)
    void ScrollEntries(int32 NumEntriesToScroll);
    
    UFUNCTION(BlueprintCallable)
    void ResearchPointBalanceChanged(float NewResearchPointBalance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItems);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTooltipOverrideChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSelectedItemTypeChanged(const UItemType* selectedItemType, bool bImmediate);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnResearchPointBalanceChanged(float NewResearchPointBalance);
    
    UFUNCTION(BlueprintCallable)
    void OnCreativeModeCatalogUnlockedChanged();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCategoryRight();
    
    UFUNCTION(BlueprintCallable)
    void OnCategoryLeft();
    
public:
    UFUNCTION(BlueprintCallable)
    void KnownItemsChanged(const TArray<TSubclassOf<UItemType>>& newKnownItems);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ESelectedItemUnlockState GetSelectedItemUnlockState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemType* GetSelectedItemType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UClass* GetSelectedItemPickupClass();
    
    UFUNCTION(BlueprintCallable)
    void ApplyPendingDisplayChanges();
    
};

