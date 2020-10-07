// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utility/CustomChildActorComponent.h"
#include "Slots/ItemSlot.h"
#include "ChildSlotComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASTRO_API UChildSlotComponent : public UCustomChildActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AItemSlot> ChildSlotClass;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//ESlottableItemsFiltrationListBehavior SlottableItemsFiltrationListBehavior;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool LockSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool SlotVisible = true;
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
