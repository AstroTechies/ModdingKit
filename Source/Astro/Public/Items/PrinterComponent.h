// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/PhysicalItem.h"
#include "Utilities/ActivationSignals.h"
#include "Slots/SlotReference.h"
#include "Components/ActorComponent.h"
#include "PrinterComponent.generated.h"

class UClickQuery;
class UTextRenderComponent;
class AControlPanel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API UPrinterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPrinterComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		bool CanReserveSlotsAcceptItemForActiveRecipe(APhysicalItem* Item);
	UFUNCTION(BlueprintCallable)
		void SetCanUse(bool bCanUse);
	UFUNCTION(BlueprintCallable)
		void OnAuthorityControlPanelCrackedChanged(AControlPanel* controlPanel);
	UFUNCTION(BlueprintCallable)
		TSubclassOf<APhysicalItem> GetCurrentItem();
	UFUNCTION(BlueprintCallable)
		bool GetCharging();
	UFUNCTION(BlueprintCallable)
		bool GetPrinting();
	UFUNCTION(BlueprintCallable)
		bool GetCanUse();
	UFUNCTION(BlueprintCallable)
		bool GetCanPrint();
	UFUNCTION(BlueprintCallable)
		bool GetItemIndicatorVisible();
	UFUNCTION(BlueprintCallable)
		bool GetItemIndicatorHidden();
	UFUNCTION(BlueprintCallable)
		TArray<TSubclassOf<UItemType>> GetSlotIndicators();
	UFUNCTION(BlueprintCallable)
		TArray<int> GetAvailableIngredientCounts();
	UFUNCTION(BlueprintCallable)
		int GetTotalAvailableBlueprintCount();
	UFUNCTION(BlueprintCallable)
		int GetCurrentUnlockedBlueprintIndex();
	UFUNCTION(BlueprintCallable)
		bool UpdatePreprinting();
	UFUNCTION(BlueprintCallable)
		void UpdatePrinting(float deltaTime);
	UFUNCTION(BlueprintCallable)
		void SetLocalIsVisible(bool isVisible);
	UFUNCTION(BlueprintCallable)
		void SetRepackageModeEnabled(bool modeEnabled);
	UFUNCTION(BlueprintCallable)
		void SetItemsAvailableToRepackage(TArray<APhysicalItem*> itemsToRepackage, int DefaultSelectionIndex);
	UFUNCTION(BlueprintCallable)
		void AddIgnoredActorForPrintAreaValidation(AActor* ignoredActor);
	UFUNCTION(BlueprintCallable)
		void RemoveIgnoredActorForPrintAreaValidation(AActor* ignoredActor);
	UFUNCTION(BlueprintCallable)
		void FinishPrinting();
	UFUNCTION(BlueprintCallable)
		void CancelPrint();
	UFUNCTION(BlueprintCallable)
		void StartPrinting();
	UFUNCTION(BlueprintCallable)
		void IncrementBlueprint(bool doServerIncrement);
	UFUNCTION(BlueprintCallable)
		void DecrementBlueprint(bool doServerIncrement);
	UFUNCTION(BlueprintCallable)
		void ActivateBlueprint();
	UFUNCTION(BlueprintCallable)
		void DeactivateBlueprint();
	UFUNCTION(BlueprintCallable)
		void HideBlueprint();
	UFUNCTION(BlueprintCallable)
		void CreateIndicatorFromClass(TSubclassOf<APhysicalItem> Class);
	UFUNCTION(BlueprintCallable)
		void CreateIndicatorFromItem(APhysicalItem* Owner);
	UFUNCTION(BlueprintCallable)
		APhysicalItem* SpawnPrintedItem();
	UFUNCTION(BlueprintCallable)
		void ResetIndicator();
	UFUNCTION(BlueprintCallable)
		void SetBlueprints(TArray<TSubclassOf<APhysicalItem>> newBlueprints);
	UFUNCTION(BlueprintCallable)
		void SetPrinterOutputSlot(FSlotReference slot);
	UFUNCTION(BlueprintCallable)
		void ShowNeededIndicators();
	UFUNCTION(BlueprintCallable)
		void HideNeededIndicators();
	UFUNCTION(BlueprintCallable)
		void SetText(FText Text);
	UFUNCTION(BlueprintCallable)
		FTransform GetPrintingTransform();
	UFUNCTION(BlueprintCallable)
		float GetPrintingHeight();
	UFUNCTION(BlueprintCallable)
		bool PrinterClickQuery(UClickQuery* Query);
	UFUNCTION(BlueprintCallable)
		void SetPrintSpeed(float speed);
	UFUNCTION(BlueprintCallable)
		void SetRequiresPower(bool printerRequiresPower);
	UFUNCTION(BlueprintCallable)
		bool GetRepackageModeEngaged();
	UFUNCTION(BlueprintCallable)
		UPrinterComponent* ActorPrinterComponent(AActor* Actor);
	UFUNCTION(BlueprintCallable)
		void UnlockedItemsChanged(TArray<TSubclassOf<UItemType>> newUnlockedItems);
	UFUNCTION(BlueprintCallable)
		void OnPrinterDestroyed(AActor* destroyedActor);
	UFUNCTION(BlueprintCallable)
		void HandleCreativeCatalogUnlockedChanged();
	UFUNCTION(BlueprintCallable)
		bool GetHasAllIngredients();
	UFUNCTION(BlueprintCallable)
		void OnRep_CurrentBlueprintItem();
	UFUNCTION(BlueprintCallable)
		void OnRep_PrinterOutputSlot();
	UFUNCTION(BlueprintCallable)
		void OnRep_PrintState();
	UFUNCTION(BlueprintCallable)
		void OnRep_SlotIndicators();
	UFUNCTION(BlueprintCallable)
		void OnRep_Progress();
	UFUNCTION(BlueprintCallable)
		void OnRep_PrinterStateAtomic();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int CurrentBlueprintIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		APhysicalItem* CurrentPackageableItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int CurrentRepackageableItemIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSlotReference> ReserveSlots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSlotReference> ResourceSlots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSubclassOf<APhysicalItem>> Blueprints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UTextRenderComponent *> TextComponents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RecipesRequireProgression;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RequireResources;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HideIndicatorWithoutFullRecipe;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RequiresPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool StreamsPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ConsumeFromStorageSlots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool AllowPrintCompletionWithoutPower = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RequiredPowerOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PrintSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool PackageUpPrintedItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ShortcutButtons;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSlotReference PrinterOutputSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSlotReference FallbackPrinterOutputSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnSetIndicatorView;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnSetPrintingView;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnSetProgressView;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FItemPrintedSignal OnFinishPrint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnCancelPrint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnStartPrint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnValidateAvailablePackageableItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool EmplaceItemAfterPrint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool InteractionEnabled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool LocalIsVisible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool PrintingActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ValidatePrintAreaOpen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PrintAreaClearRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Progress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ProgressOverride;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SlotIndicatorIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSubclassOf<UItemType>> NeededItemTypes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RepackageModeEngaged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInstanceDynamic* PrintingMaterialDynamic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor*> ActorsIgnoredDuringPrintAreaValidation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSlotReference> PlayerStorageSlots;
};
