// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utility/CustomChildActorComponent.h"
#include "ChildSlotComponent.generated.h"

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

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASTRO_API UChildSlotComponent : public UCustomChildActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESlottableItemsFiltrationListBehavior SlottableItemsFiltrationListBehavior;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool LockSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool SlotVisible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Unclickable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Breakable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ConnectionPullAllowed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HideConnectorOnPull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool GeneratesNoCollision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool WeldItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAuxSlotType AuxSlotType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESlotConnectorType ConnectorType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESlotConfiguration Configuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsStorage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsTruck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool AllowBodySlotAttach;
};
