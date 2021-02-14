// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Slots/SlotReference.h"
#include "GameFramework/Actor.h"
#include "Items/ItemType.h"
#include "Slots/SlotConnection.h"
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

UENUM(BlueprintType)
enum class ESlottableItemsFiltrationListBehavior : uint8 {
	Ignore = 0,
	Whitelist = 1,
	Blacklist = 2
};

UENUM(BlueprintType)
enum class EAuxSlotType : uint8 {
	None = 0,
	Left = 1,
	Right = 2,
	LeftAndRight = 3
};

UENUM(BlueprintType)
enum class ESlotConnectorType : uint8 {
	Plug = 0,
	Socket = 1
};

UENUM(BlueprintType)
enum class ESlotConfiguration : uint8 {
	Vertical = 0,
	VerticalLeft = 1,
	Horizontal = 2,
	CameraFacingLeft = 3,
	CameraFacingRight = 4,
	HorizontalAux = 5,
	VerticalAux = 6
};

UENUM(BlueprintType)
enum class ESlotPosition : uint8 {
	RelativeTransform = 0,
	Socket = 1,
	SceneComponent = 2
};

USTRUCT(BlueprintType)
struct ASTRO_API FSubSlotLocation {
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform RelativeOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 Tier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 ParentSubslotIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 LeftChildSubslotIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 RightChildSubslotIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 NumChildren;
};

USTRUCT(BlueprintType)
struct ASTRO_API FSlot {
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AItemSlot> SlotTemplate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESlotType SlotType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESlotConnectorType ConnectorType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SlotTier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SlotBinaryTreeDepth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SlotTierCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Breakable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsReserved;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESlotConfiguration Configuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESlotPosition PositionType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName TargetName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName SocketName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTransform RelativeOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector ConnectionAdditionalRelativeOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSubSlotLocation> SubslotLocations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ASlotConnection> ConnectionClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsBodySlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAllowBodySlotAttach;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bGenerateNoCollision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanHoldItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bItemBlocksConnection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bConnectionBlocksItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bNoConnectionPull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSingleConnection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHideConnectorOnPull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bConnectionTense;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bUnclickable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsManagedByRule;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSlotIsHidden;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHasExternallyManagedConnection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanAcceptUnslottableItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsTrailerHitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bPowerIncomingOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bStreamingPowerConnectionsMergeNodes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bWeldItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSwapInProgress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bWillBeSlottedTo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAuxSlotType AuxSlotType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TraceRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float IndicatorScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSlotReference CurrentBodySlot;
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

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UClickableComponent* ClickableComponent;

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
		bool CanAcceptItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString HoverSoundEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString AttachSoundEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString DetachSoundEvent;
};
