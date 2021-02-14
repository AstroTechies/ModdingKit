// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/ActivationSignals.h"
#include "Items/ItemType.h"
#include "Items/SlotAutoOrganization/SlotOrganizationRule.h"
#include "Components/ActorComponent.h"
#include "StorageChassisComponent.generated.h"

class AActor;
class APlayerController;
class APhysicalItem;
class USlotOrganizationRule;
class UActorAttachmentsComponent;

USTRUCT(BlueprintType)
struct ASTRO_API FSlotIndicatorDefinition
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UItemType> IndicatorItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		APhysicalItem* WhitelistCohabitationItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EIndicatorTooltipType TooltipType;
};

USTRUCT(BlueprintType)
struct ASTRO_API FSlotIndicatorLocation
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SubslotIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSlotReference SlotForIndicator;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSlotIndicatorDefinition IndicatorDef;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API UStorageChassisComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStorageChassisComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		bool QueryTertiary(APlayerController* Controller, FTransform OutTransform);
	UFUNCTION(BlueprintCallable)
		void TertiaryUse(APlayerController* Controller);
	UFUNCTION(BlueprintCallable)
		void SlotEvent(APhysicalItem* item);
	UFUNCTION(BlueprintCallable)
		void ItemAmountChangeEvent();
	UFUNCTION(BlueprintCallable)
		UStorageChassisComponent* GetActorStorageChassisComponent(AActor* Actor);
	UFUNCTION(BlueprintCallable)
		int ChangeDeformationDeltaInConnectedSlotNetwork(int sedimentAmount, TSubclassOf<UItemType> deformedItemType);
	UFUNCTION(BlueprintCallable)
		void CalculateItemReservesInConnectedSlotNetwork(TSubclassOf<UItemType> ItemType, int outCurrentStoredItemAmount, int outMaxStorageSize);
	UFUNCTION(BlueprintCallable)
		bool AuthorityPlaceItemInConnectedSlotNetwork(APhysicalItem* Item, AActor* SourceOwner);
	UFUNCTION(BlueprintCallable)
		bool AuthorityPlaceItemInLocalStorage(APhysicalItem* Item);
	UFUNCTION(BlueprintCallable)
		int AddItem(TSubclassOf<UItemType> itemType, int itemAmount);
	UFUNCTION(BlueprintCallable)
		UStorageChassisComponent* GetOutermostStorage(AActor* Actor, bool Inclusive);
	UFUNCTION(BlueprintCallable)
		TArray<FSlotReference> GetUnmanagedSlots();
	UFUNCTION(BlueprintCallable)
		USlotOrganizationRule* FindRuleByName(FName ruleName);
	UFUNCTION(BlueprintCallable)
		void AuthorityApplyOrganizationRules();
	UFUNCTION(BlueprintCallable)
		void OnRep_SlotIndicatorLocations();
	UFUNCTION(BlueprintCallable)
		void OnRep_ActorAttachments();
	UFUNCTION(BlueprintCallable)
		void OnPlayerEnterExitAttachment(bool entered);
	UFUNCTION(BlueprintCallable)
		void OnOwnerDestroyed(AActor* owner);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FOnSlotEventSignal OnSlotEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnSlotsReset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnItemAmountChangeEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSlotReference> ExcludeSlots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UActorAttachmentsComponent *> ActorAttachments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanExit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IndicateExit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool OwnerFacingBack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool TertiaryUsable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool SaveOnEnter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanTransferItemsAcrossConnections;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSlotReference> RailSlots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnTertiaryUse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FEnterExitSignal OnTertiaryEnterExit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSlotReference> Slots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UStorageChassisComponent *> ChildStorageChassis;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		TArray<USlotOrganizationRule *> OrganizationRules;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSlotIndicatorLocation> SlotIndicatorLocations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSlotIndicatorLocation> PreviousSlotIndicatorLocations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsSpawnPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsNewPlayerSpawnPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsDefaultSpawnPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SpawnPointPriority;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UActorAttachmentsComponent *> PrevActorAttachments;
};
