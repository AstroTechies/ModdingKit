// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/ClickableComponent.h"
#include "ItemSlot.generated.h"

UENUM(BlueprintType)
enum class ESlotType : uint8 {
	Power = 0,
	Resource = 1,
	Control = 2,
	Tether = 3,
	Rail = 4,
	Inert = 5,
	PowerResource = 6,
	ChassisBlock = 7,
	IDCard = 8,
	Schematic = 9
};

UCLASS(BlueprintType, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASTRO_API AItemSlot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemSlot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESlotType SlotType;

	/*TSubclassOf<AItemSlot> BaseClassType;
	TArray<TSubclassOf<USlotBehavior>,FDefaultAllocator> Behaviors;
	FScriptContainerElement* Data;
	USubslot* SubSlot;
	TSubclassOf<ASlotConnection> ConnectionClass;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector ConnectionAnchorOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool SingleConnection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ItemBlocksConnection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ConnectionBlocksItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ConnectionTense;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool PowerIncomingOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool StreamingPowerConnectionsMergePowerNodes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanAcceptUnslottableItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsTrailerHitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SlotTier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SlotTierCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanHoldItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UClickableComponent* ClickableComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanAcceptItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString HoverSoundEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString AttachSoundEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString DetachSoundEvent;
};
