#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "ReplicatedPrinterState.h"
#include "SlotReference.h"
#include "ItemPrintedSignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "PrinterComponent.generated.h"

class UTextRenderComponent;
class AControlPanel;
class APhysicalItem;
class UPrinterComponent;
class UMaterialInstanceDynamic;
class AActor;
class URecipeOrganizationRule;
class UItemType;
class UAstroSaveCustomArchiveProxy;
class UClickQuery;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
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
    
    UPROPERTY(EditAnywhere, SaveGame)
    TArray<uint32> TotalItemAmounts;
    
    UPROPERTY(EditAnywhere, SaveGame)
    TArray<uint32> ConsumedItemAmounts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsIgnoredDuringPrintAreaValidation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> PlayerStorageSlots;
    
    UPROPERTY(EditAnywhere)
    TWeakObjectPtr<URecipeOrganizationRule> RecipeOrganizationRule;
    
public:
    UPrinterComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION()
    void UnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItems);
    
    UFUNCTION(BlueprintCallable)
    void StartPrinting();
    
    UFUNCTION(BlueprintCallable)
    APhysicalItem* SpawnPrintedItem();
    
    UFUNCTION(BlueprintCallable)
    void SetText(FText Text);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetRequiresPower(bool printerRequiresPower);
    
    UFUNCTION()
    void SetRepackageModeEnabled(bool modeEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetPrintSpeed(float Speed);
    
    UFUNCTION(BlueprintCallable)
    void SetPrinterOutputSlot(const FSlotReference& Slot);
    
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
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveIgnoredActorForPrintAreaValidation(AActor* ignoredActor);
    
    UFUNCTION(BlueprintCallable)
    bool PrinterClickQuery(UClickQuery* Query);
    
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
    void OnPrinterDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void OnAuthorityControlPanelCrackedChanged(AControlPanel* ControlPanel);
    
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
    void CreateIndicatorFromItem(APhysicalItem* Owner);
    
    UFUNCTION(BlueprintCallable)
    void CreateIndicatorFromClass(TSubclassOf<APhysicalItem> Class);
    
    UFUNCTION(BlueprintPure)
    bool CanReserveSlotsAcceptItemForActiveRecipe(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void CancelPrint(bool restoreIngredients);
    
    UFUNCTION(BlueprintCallable)
    void AddIgnoredActorForPrintAreaValidation(AActor* ignoredActor);
    
    UFUNCTION(BlueprintPure)
    static UPrinterComponent* ActorPrinterComponent(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void ActivateBlueprint();
    
};

