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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UItemComponent* ItemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UActorEntityLinkComponent* EntityLinkComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UTerrainPhysicsComponent* TerrainComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UWorldGravity* GravityComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UClickableComponent* ClickableComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USlotsComponent* SlotsComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UTooltipComponent* TooltipComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UProceduralStateComponent* ProceduralState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// no idea
		float HoverHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// The height of the printer, overrides the default determined height value if defined
		float PrinterHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (UIMin = "0", UIMax = "4"))
		// The tier of the object. 1 = T1, 2 = T2, etc. Controls fallback slot size as well as walking speed
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
