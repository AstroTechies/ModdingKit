// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Items/ItemComponent.h"
#include "EntityModel/ActorEntityLinkComponent.h"
#include "Terrain/TerrainPhysicsComponent.h"
#include "Interaction/ClickableComponent.h"
#include "Slots/SlotsComponent.h"
#include "Interaction/TooltipComponent.h"
#include "EntityModel/EntityComponents/AstroEntityProceduralStateComponent.h"
#include "Planet/WorldGravity.h"
#include "Utilities/ActivationSignals.h"
#include "GameFramework/Actor.h"
#include "PhysicalItem.generated.h"

UCLASS(BlueprintType)
class ASTRO_API APhysicalItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysicalItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UItemComponent* ItemComponent;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UActorEntityLinkComponent* EntityLinkComponent;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UTerrainPhysicsComponent* TerrainComponent;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UWorldGravity* GravityComponent;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UClickableComponent* ClickableComponent;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		USlotsComponent* SlotsComponent;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UTooltipComponent* TooltipComponent;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UProceduralStateComponent* ProceduralState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// no idea
		float HoverHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// The height of the printer, overrides the default determined height value if defined
		float PrinterHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (UIMin = "0", UIMax = "4"))
		// The tier of the object. 1 = T1, 2 = T2, etc. Controls fallback slot size, default package size, as well as walking speed
		int ToolMoveTier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Can this item be picked up and moved around with the cursor?
		bool IsMovable = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Can this item be slotted?
		bool IsUnslottable = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Can this item be directly attached to the body of an object (like packagers and dynamite do)?
		bool SlotQueryAllowBodyPlacement = false;

public:
	/* Signals */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnItemUnpacked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnPlacedInSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnSpawnedInSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnEmplacedInSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnUnemplacedFromSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnFullyEmplaced;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FOnSlotReleased OnReleasedFromSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnReleasedFromSlotClientSafe;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FItemDropInWorldDelegate OnDroppedInWorld;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FItemDropInWorldTerrainDelegate OnDroppedInWorldTerrain;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FOnPickedUp OnPickedUpFromWorld;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnStartInWorld;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FOnMoved OnMoved;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnMotionStateChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FSignal OnSetCardinalDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
		FOnReplicationDataChanged OnReplicationDataChanged;
};
