#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "SignalDelegate.h"
#include "ItemPrintedSignalDelegate.h"
#include "ReplicatedPrinterState.h"
#include "UObject/NoExportTypes.h"
#include "PrinterComponent.generated.h"

class UTextRenderComponent;
class APhysicalItem;
class UMaterialInstanceDynamic;
class AActor;
class URecipeOrganizationRule;
class AControlPanel;
class UItemType;
class UAstroSaveCustomArchiveProxy;
class UClickQuery;
class UPrinterComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UPrinterComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    int32 CurrentBlueprintIndex;

    UPROPERTY()
    APhysicalItem *CurrentPackageableItem;

    UPROPERTY()
    int32 CurrentRepackageableItemIndex;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> ReserveSlots;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> ResourceSlots;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<TSubclassOf<APhysicalItem>> Blueprints;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    TArray<UTextRenderComponent *> TextComponents;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool RecipesRequireProgression;

    UPROPERTY(EditAnywhere)
    bool RequireResources;

    UPROPERTY(EditAnywhere)
    bool HideIndicatorWithoutFullRecipe;

    UPROPERTY(EditAnywhere)
    bool RequiresPower;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool StreamsPower;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool ConsumeFromStorageSlots;

    UPROPERTY(EditAnywhere)
    bool AllowPrintCompletionWithoutPower;

    UPROPERTY(EditAnywhere)
    float RequiredPowerOffset;

    UPROPERTY(EditAnywhere)
    float PrintSpeed;

    UPROPERTY(EditAnywhere)
    bool PackageUpPrintedItems;

    UPROPERTY(EditAnywhere)
    bool ShortcutButtons;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference PrinterOutputSlot;

    UPROPERTY(SaveGame)
    FSlotReference FallbackPrinterOutputSlot;

    UPROPERTY(BlueprintAssignable)
    FSignal OnSetIndicatorView;

    UPROPERTY(BlueprintAssignable)
    FSignal OnSetPrintingView;

    UPROPERTY(BlueprintAssignable)
    FSignal OnSetProgressView;

    UPROPERTY(BlueprintAssignable)
    FItemPrintedSignal OnFinishPrint;

    UPROPERTY(BlueprintAssignable)
    FSignal OnCancelPrint;

    UPROPERTY(BlueprintAssignable)
    FSignal OnStartPrint;

    UPROPERTY(BlueprintAssignable)
    FSignal OnValidateAvailablePackageableItems;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool EmplaceItemAfterPrint;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool InteractionEnabled;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool LocalIsVisible;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool PrintingActive;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool ValidatePrintAreaOpen;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PrintAreaClearRadius;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    float Progress;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    float ProgressOverride;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 SlotIndicatorIndex;

protected:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool RepackageModeEngaged;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_PrinterStateAtomic, meta = (AllowPrivateAccess = true))
    FReplicatedPrinterState REP_PrinterState;

private:
    UPROPERTY(Transient)
    FReplicatedPrinterState PrevReplicatedState;

    UPROPERTY()
    UMaterialInstanceDynamic *PrintingMaterialDynamic;

    UPROPERTY(SaveGame)
    TArray<uint32> TotalItemAmounts;

    UPROPERTY(SaveGame)
    TArray<uint32> ConsumedItemAmounts;

    UPROPERTY(SaveGame)
    TArray<AActor *> ActorsIgnoredDuringPrintAreaValidation;

    UPROPERTY()
    TArray<FSlotReference> PlayerStorageSlots;

    UPROPERTY()
    TWeakObjectPtr<URecipeOrganizationRule> RecipeOrganizationRule;

public:
    UPrinterComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void UnlockedItemsChanged(const TArray<TSubclassOf<UItemType>> &NewUnlockedItems);

    UFUNCTION(BlueprintCallable)
    void StartPrinting();

    UFUNCTION(BlueprintCallable)
    APhysicalItem *SpawnPrintedItem();

    UFUNCTION(BlueprintCallable)
    void SetText(FText Text);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetRequiresPower(bool printerRequiresPower);

    UFUNCTION()
    void SetRepackageModeEnabled(bool modeEnabled);

    UFUNCTION(BlueprintCallable)
    void SetPrintSpeed(float Speed);

    UFUNCTION(BlueprintCallable)
    void SetPrinterOutputSlot(const FSlotReference &Slot);

    UFUNCTION(BlueprintCallable)
    void SetLocalIsVisible(bool IsVisible);

    UFUNCTION()
    void SetItemsAvailableToRepackage(TArray<TWeakObjectPtr<APhysicalItem>> itemsToRepackage, int32 DefaultSelectionIndex);

    UFUNCTION(BlueprintAuthorityOnly)
    void SetCanUse(bool bCanUse);

    UFUNCTION(BlueprintCallable)
    void SetBlueprints(TArray<TSubclassOf<APhysicalItem>> newBlueprints);

protected:
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);

public:
    UFUNCTION(BlueprintCallable)
    void RemoveIgnoredActorForPrintAreaValidation(AActor *ignoredActor);

    UFUNCTION(BlueprintCallable)
    bool PrinterClickQuery(UClickQuery *Query);

private:
    UFUNCTION()
    void OnRep_Progress();

    UFUNCTION()
    void OnRep_PrintState();

    UFUNCTION()
    void OnRep_PrinterStateAtomic();

    UFUNCTION()
    void OnRep_PrinterOutputSlot();

    UFUNCTION()
    void OnRep_CurrentBlueprintItem();

protected:
    UFUNCTION()
    void OnPrinterDestroyed(AActor *DestroyedActor);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void OnAuthorityControlPanelCrackedChanged(AControlPanel *ControlPanel);

    UFUNCTION(BlueprintCallable)
    void IncrementBlueprint(bool doServerIncrement);

    UFUNCTION(BlueprintCallable)
    void HideBlueprint();

protected:
    UFUNCTION()
    void HandleCreativeCatalogUnlockedChanged();

public:
    UFUNCTION(BlueprintPure)
    int32 GetTotalAvailableBlueprintCount() const;

    UFUNCTION()
    bool GetRepackageModeEngaged() const;

    UFUNCTION(BlueprintCallable)
    FTransform GetPrintingTransform();

    UFUNCTION(BlueprintCallable)
    float GetPrintingHeight();

    UFUNCTION(BlueprintPure)
    bool GetPrinting() const;

    UFUNCTION(BlueprintPure)
    bool GetItemIndicatorVisible() const;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    bool GetItemIndicatorHidden() const;

protected:
    UFUNCTION(BlueprintPure)
    bool GetHasAllIngredients() const;

public:
    UFUNCTION(BlueprintPure)
    int32 GetCurrentUnlockedBlueprintIndex() const;

    UFUNCTION(BlueprintPure)
    TSubclassOf<APhysicalItem> GetCurrentItem() const;

    UFUNCTION(BlueprintPure)
    bool GetCharging() const;

    UFUNCTION(BlueprintPure)
    bool GetCanUse() const;

    UFUNCTION(BlueprintPure)
    bool GetCanPrint() const;

    UFUNCTION(BlueprintPure)
    TArray<int32> GetAvailableIngredientCounts() const;

    UFUNCTION(BlueprintCallable)
    void FinishPrinting();

    UFUNCTION(BlueprintCallable)
    void DecrementBlueprint(bool doServerIncrement);

    UFUNCTION(BlueprintCallable)
    void DeactivateBlueprint();

    UFUNCTION(BlueprintCallable)
    void CreateIndicatorFromItem(APhysicalItem *Owner);

    UFUNCTION(BlueprintCallable)
    void CreateIndicatorFromClass(TSubclassOf<APhysicalItem> Class);

    UFUNCTION(BlueprintPure)
    bool CanReserveSlotsAcceptItemForActiveRecipe(APhysicalItem *Item);

    UFUNCTION(BlueprintCallable)
    void CancelPrint(bool restoreIngredients);

    UFUNCTION(BlueprintCallable)
    void AddIgnoredActorForPrintAreaValidation(AActor *ignoredActor);

    UFUNCTION(BlueprintPure)
    static UPrinterComponent *ActorPrinterComponent(AActor *Actor);

    UFUNCTION(BlueprintCallable)
    void ActivateBlueprint();
};
