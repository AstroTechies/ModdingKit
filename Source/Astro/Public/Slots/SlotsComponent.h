// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/ItemType.h"
#include "StorageChassisComponent.h"
#include "Slots/SlotConnection.h"
#include "Slots/SlotReference.h"
#include "Slots/ItemSlot.h"
#include "Engine/EngineBaseTypes.h"
#include "SlotsComponent.generated.h"

class APhysicalItem;
class AAstroPlayerController;

UCLASS(EditInlineNew, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API USlotsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USlotsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		FSlotReference MakeReference(FName SlotName);
	UFUNCTION(BlueprintCallable)
		bool SlotValid(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		bool SlotValidSlow(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		void SetSlotRelativeTransform(FSlotReference Slot, FTransform transform);
	UFUNCTION(BlueprintCallable)
		void SetSlotAcceptsItems(FSlotReference A, bool bAcceptsItems);
	UFUNCTION(BlueprintCallable)
		void SetSlotClickable(FSlotReference A, bool Clickable);
	UFUNCTION(BlueprintCallable)
		void SetSlotHidden(FSlotReference slotRef, bool bIsHidden);
	UFUNCTION(BlueprintCallable)
		void ConnectPowerToItem(FSlotReference slotRef, APhysicalItem* item);
	UFUNCTION(BlueprintCallable)
		ASlotConnection* MakeConnection(FSlotReference a, FSlotReference b, TSubclassOf<ASlotConnection> OverrideType, bool Visible);
	UFUNCTION(BlueprintCallable)
		ASlotConnection* MakeExclusiveConnection(FSlotReference a, FSlotReference b, TSubclassOf<ASlotConnection> OverrideType);
	UFUNCTION(BlueprintCallable)
		void BreakAllSlotConnections(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		APhysicalItem* SpawnActorInSlot(FSlotReference Slot, TSubclassOf<APhysicalItem> Class);
	UFUNCTION(BlueprintCallable)
		bool SpawnItemTypeInSlot(FSlotReference Slot, TSubclassOf<UItemType> Type, bool StartFull);
	UFUNCTION(BlueprintCallable)
		bool SpawnItemTypeInSlotWithDefaultContainer(FSlotReference Slot, TSubclassOf<UItemType> Type, TSubclassOf<UItemType> DefaultContainerType, bool StartFull);
	UFUNCTION(BlueprintCallable)
		void DestroySlotItem(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		void ReleaseItem(APhysicalItem* item, bool newOwner, bool FromTool, float RandomForce);
		void ReleaseItem(FSlotReference Slot, APhysicalItem* item, bool newOwner, bool FromTool, float RandomForce);
	UFUNCTION(BlueprintCallable)
		void ReleaseItemWithEjectionImpulse(APhysicalItem* item, bool newOwner, bool FromTool, FVector ejectionImpulse, FVector ejectionImpulseOffset);
		void ReleaseItemWithEjectionImpulse(FSlotReference Slot, APhysicalItem* item, bool newOwner, bool FromTool, FVector ejectionImpulse, FVector ejectionImpulseOffset);
	UFUNCTION(BlueprintCallable)
		void ReleaseSlotItemForce(FSlotReference Slot, float RandomForce);
	UFUNCTION(BlueprintCallable)
		void EmplaceSlotItem(FSlotReference Slot, APhysicalItem* item, bool snapTo, bool weld);
	UFUNCTION(BlueprintCallable)
		bool TakeSlotItemFromOther(FSlotReference Slot, FSlotReference Other);
	UFUNCTION(BlueprintCallable)
		bool TakeSlotItemOfTypeFromOther(FSlotReference Slot, FSlotReference Other, TSubclassOf<UItemType> type);
	UFUNCTION(BlueprintCallable)
		int SlotGetNumIndicators(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		bool SlotAddIndicatorItem(FSlotReference Slot, TSubclassOf<APhysicalItem> type);
	UFUNCTION(BlueprintCallable)
		bool SlotAddIndicatorItemType(FSlotReference Slot, TSubclassOf<UItemType> itemType);
	UFUNCTION(BlueprintCallable)
		bool SlotAddIndicatorItemAttemptPackage(FSlotReference Slot, TSubclassOf<APhysicalItem> type);
	UFUNCTION(BlueprintCallable)
		bool SlotAddIndicatorItemTypeAttemptPackage(FSlotReference Slot, TSubclassOf<UItemType> itemType);
	UFUNCTION(BlueprintCallable)
		int SlotAttemptToPushIndicatorIntoSpecificSubslot(FSlotReference Slot, int SubslotIndex, FSlotIndicatorDefinition IndicatorDefinition);
	UFUNCTION(BlueprintCallable)
		int SlotPushIndicatorItemTypes(FSlotReference Slot, int Count, TArray<int> OutSubslotIndices, FSlotIndicatorDefinition IndicatorDefinition);
	UFUNCTION(BlueprintCallable)
		void SlotDestroyIndicators(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		void SlotEnable(FSlotReference slotRef, bool Enable);
	UFUNCTION(BlueprintCallable)
		void SetSlotBreakable(FSlotReference slotRef, bool Breakable);
	UFUNCTION(BlueprintCallable)
		ESlotType GetSlotType(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		void SetSlotAcceptsUnslottableItems(FSlotReference SlotRef, bool bAcceptsUnslottableItems);
	UFUNCTION(BlueprintCallable)
		bool SlotAcceptsItem(FSlotReference Slot, APhysicalItem* Item);
	UFUNCTION(BlueprintCallable)
		bool SlotAcceptsItemTypeWithChangeInAmount(FSlotReference Slot, TSubclassOf<UItemType> itemType, bool isChangePositive);
	UFUNCTION(BlueprintCallable)
		bool SlotAttemptToChangeItemAmountNormalized(FSlotReference Slot, TSubclassOf<UItemType> itemType, float normalizedAmount);
	UFUNCTION(BlueprintCallable)
		bool SlotIsTrailerHitch(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		bool SlotPowerIncomingOnly(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		int SlotGetTier(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		USlotsComponent* GetSlotOwner(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		TArray<UStaticMeshComponent *> GetSlotLegacyMeshes(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		FTransform GetSlotTransform(FSlotReference Slot);
		bool GetSlotTransform(FName slotName, FTransform outTransform);
	UFUNCTION(BlueprintCallable)
		FTransform GetSlotRelativeTransform(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		APhysicalItem* GetSlotPrimaryItem(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		APhysicalItem* GetSlotItem(FSlotReference Slot, int SubslotIndex);
	UFUNCTION(BlueprintCallable)
		TArray<APhysicalItem *> GetSlotItems(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		FSlotReference GetSlotConnectedSlot(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		ESlotConfiguration GetSlotOrientationConfiguration(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		ESlotConnectorType GetSlotConnectorType(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		bool SlotsEqual(FSlotReference A, FSlotReference B);
	/*UFUNCTION(BlueprintCallable)
		USlotDelegates* GetSlotDelegates(FSlotReference Slot);*/
	UFUNCTION(BlueprintCallable)
		TArray<ASlotConnection *> GetSlotExternalConnections(FSlotReference Slot);
	UFUNCTION(BlueprintCallable)
		void OnSlotItemDestroyed(AActor* actor);
	UFUNCTION(BlueprintCallable)
		void OnRep_SlotTransitions();
	UFUNCTION(BlueprintCallable)
		void OnSlotIndicatorClicked(FSlotReference Slot, TSubclassOf<UItemType> Type);
	UFUNCTION(BlueprintCallable)
		void SetTracePrimitivesAsleep(bool bAreAsleep);
	UFUNCTION(BlueprintCallable)
		void AuxUse(FSlotReference auxSlot, AAstroPlayerController* controller, EInputEvent inputEvent);
	UFUNCTION(BlueprintCallable)
		void AuxUseAll(AAstroPlayerController* controller, EInputEvent inputEvent);
	UFUNCTION(BlueprintCallable)
		void AuxUseLeft(AAstroPlayerController* controller, EInputEvent inputEvent);
	UFUNCTION(BlueprintCallable)
		void AuxUseRight(AAstroPlayerController* controller, EInputEvent inputEvent);
	UFUNCTION(BlueprintCallable)
		void MulticastCancelSlotBehaviorTerrainInterpolation();
	UFUNCTION(BlueprintCallable)
		void OnRep_SlotRuleStatus();
	UFUNCTION(BlueprintCallable)
		void OnRep_SlotClickability();
	UFUNCTION(BlueprintCallable)
		void OnRep_SlotsAcceptItems();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSlot> Slots;
};