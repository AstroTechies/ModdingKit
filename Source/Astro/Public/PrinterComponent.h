#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ItemBlueprintRow.h"
#include "ItemPrintedSignalDelegate.h"
#include "ReplicatedPrinterState.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "PrinterComponent.generated.h"

class AActor;
class AControlPanel;
class APhysicalItem;
class UAstroSaveCustomArchiveProxy;
class UClickQuery;
class UItemCatalogCategoryDefinition;
class UItemType;
class UMaterialInstanceDynamic;
class UPrinterComponent;
class URecipeOrganizationRule;
class UTextRenderComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UPrinterComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentBlueprintIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* CurrentPackageableItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentRepackageableItemIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ReserveSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ResourceSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<APhysicalItem>> Blueprints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemCatalogCategoryDefinition* DefaultBlueprintPrinterCatagory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTextRenderComponent*> TextComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RecipesRequireProgression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequireResources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HideIndicatorWithoutFullRecipe;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequiresPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StreamsPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ConsumeFromStorageSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowPrintCompletionWithoutPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RequiredPowerOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrintSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PackageUpPrintedItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShortcutButtons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference PrinterOutputSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference FallbackPrinterOutputSlot;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSetIndicatorView;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSetPrintingView;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSetProgressView;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemPrintedSignal OnFinishPrint;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCancelPrint;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStartPrint;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnValidateAvailablePackageableItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EmplaceItemAfterPrint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InteractionEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LocalIsVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PrintingActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ValidatePrintAreaOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrintAreaClearRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float Progress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float ProgressOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SlotIndicatorIndex;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RepackageModeEngaged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_PrinterStateAtomic, meta=(AllowPrivateAccess=true))
    FReplicatedPrinterState REP_PrinterState;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FReplicatedPrinterState PrevReplicatedState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PrintingMaterialDynamic;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint32> TotalItemAmounts;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint32> ConsumedItemAmounts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsIgnoredDuringPrintAreaValidation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> PlayerStorageSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<URecipeOrganizationRule> RecipeOrganizationRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemBlueprintRow> BlueprintRows;
    
public:
    UPrinterComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItems);
    
    UFUNCTION(BlueprintCallable)
    void StartPrinting();
    
    UFUNCTION(BlueprintCallable)
    APhysicalItem* SpawnPrintedItem();
    
    UFUNCTION(BlueprintCallable)
    void SetText(FText Text);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetRequiresPower(bool printerRequiresPower);
    
    UFUNCTION(BlueprintCallable)
    void SetRepackageModeEnabled(bool modeEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetPrintSpeed(float Speed);
    
    UFUNCTION(BlueprintCallable)
    void SetPrinterOutputSlot(const FSlotReference& Slot);
    
    UFUNCTION(BlueprintCallable)
    void SetLocalIsVisible(bool IsVisible);
    
    UFUNCTION()
    void SetItemsAvailableToRepackage(TArray<TWeakObjectPtr<APhysicalItem>> itemsToRepackage, int32 DefaultSelectionIndex);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetCanUse(bool bCanUse);
    
    UFUNCTION(BlueprintCallable)
    void SetBlueprints(TArray<TSubclassOf<APhysicalItem>> newBlueprints);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveIgnoredActorForPrintAreaValidation(AActor* ignoredActor);
    
    UFUNCTION(BlueprintCallable)
    bool PrinterClickQuery(UClickQuery* Query);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_Progress();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_PrintState();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_PrinterStateAtomic();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_PrinterOutputSlot();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentBlueprintItem();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPrinterDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void OnAuthorityControlPanelCrackedChanged(AControlPanel* ControlPanel);
    
    UFUNCTION(BlueprintCallable)
    void IncrementBlueprintRow(bool doServerIncrement);
    
    UFUNCTION(BlueprintCallable)
    void IncrementBlueprint(bool doServerIncrement);
    
    UFUNCTION(BlueprintCallable)
    void HideBlueprint();
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleCreativeModeOrEventStatusChanged();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTotalVisibleBlueprintRowsCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTotalVisibleBlueprintColumnCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetRowSelectableStates(TArray<bool>& rowStates) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetRepackageModeEngaged() const;
    
    UFUNCTION(BlueprintCallable)
    FTransform GetPrintingTransform();
    
    UFUNCTION(BlueprintCallable)
    float GetPrintingHeight();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPrinting() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetItemIndicatorVisible() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool GetItemIndicatorHidden() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHasAllIngredients() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentVisibleRowBlueprintIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentVisibleColumnBlueprintIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<APhysicalItem> GetCurrentItem() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetColumnSelectableStates(TArray<bool>& columnStates) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCharging() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCanUse() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCanPrint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetAvailableIngredientCounts() const;
    
    UFUNCTION(BlueprintCallable)
    void FinishPrinting();
    
    UFUNCTION(BlueprintCallable)
    void DecrementBlueprintRow(bool doServerIncrement);
    
    UFUNCTION(BlueprintCallable)
    void DecrementBlueprint(bool doServerIncrement);
    
    UFUNCTION(BlueprintCallable)
    void DeactivateBlueprint();
    
    UFUNCTION(BlueprintCallable)
    void CreateIndicatorFromItem(APhysicalItem* Owner);
    
    UFUNCTION(BlueprintCallable)
    void CreateIndicatorFromClass(TSubclassOf<APhysicalItem> Class);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanReserveSlotsAcceptItemForActiveRecipe(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void CancelPrint(bool restoreIngredients);
    
    UFUNCTION(BlueprintCallable)
    void AddIgnoredActorForPrintAreaValidation(AActor* ignoredActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UPrinterComponent* ActorPrinterComponent(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void ActivateBlueprint();
    
};

