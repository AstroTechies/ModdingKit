// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slots/SlotReference.h"
#include "Items/ItemType.h"
#include "FuelConsumerComponent.generated.h"

class APhysicalItem;
class USlotsComponent;
class AAstroCharacter;

UENUM(BlueprintType)
enum class EFuelSource : uint8 {
	InternalPortioned = 0,
	External = 1
};

UCLASS(EditInlineNew, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASTRO_API UFuelConsumerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void OnItemSlotted(APhysicalItem* item);
	UFUNCTION(BlueprintCallable) void OnItemRemoved(APhysicalItem* item);
	UFUNCTION(BlueprintCallable) void OnItemAmountChanged();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bOperatesOnCharacterOnly = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float LowFuelThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FuelPerPortion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName FuelSlotName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FSlotReference FuelSlotRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EFuelSource FuelSource;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<UItemType> FuelType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ConsumptionRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float NetworkSyncFuelTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USlotsComponent* SlotsComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) APhysicalItem* ItemOwner;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AAstroCharacter* AstroCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FSlotReference> DestinationSlots;
};