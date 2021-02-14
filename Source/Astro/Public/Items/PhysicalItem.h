// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Slots/SlotReference.h"
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
#include "Engine/EngineTypes.h"
#include "PhysicalItem.generated.h"

class UPrimitiveComponent;
class UChildSlotComponent;
class APawn;

UENUM(BlueprintType)
enum class EPhysicalItemMotionState : uint8 {
	Simulating = 0,
	PickedUp = 1,
	Slotted = 2,
	NonSimulating = 3,
	Indicator = 4
};

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

	UFUNCTION(BlueprintCallable)
		bool Movable(int ToolTier);
	UFUNCTION(BlueprintCallable)
		void StartItemInWorld();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		UChildSlotComponent* GetBodySlotLegacy();
	UFUNCTION(BlueprintCallable)
		FSlotReference GetBodySlot();
	UFUNCTION(BlueprintCallable)
		FTransform PlacementTransform(FHitResult Hit);
	UFUNCTION(BlueprintCallable)
		void DropInWorld(UPrimitiveComponent* Component, bool terrainComponent, FVector Point, FVector Normal);
	UFUNCTION(BlueprintCallable)
		void PickUpFromWorld(bool physicalMovement);
	UFUNCTION(BlueprintCallable)
		FTransform GetBaseLocation();
	UFUNCTION(BlueprintCallable)
		FText GetItemName();
	UFUNCTION(BlueprintCallable)
		float GetPrinterHeight();
	UFUNCTION(BlueprintCallable)
		TSubclassOf<UItemType> GetFunctionalItemTypeClass();
	UFUNCTION(BlueprintCallable)
		TSubclassOf<UItemType> GetStoredSubItemTypeClass();
	UFUNCTION(BlueprintCallable)
		TSubclassOf<UItemType> GetLiteralItemTypeClass();
	UFUNCTION(BlueprintCallable)
		UItemType* GetFunctionalItemTypeCDO();
	UFUNCTION(BlueprintCallable)
		UItemType* GetStoredSubItemTypeCDO();
	UFUNCTION(BlueprintCallable)
		UItemType* GetLiteralItemTypeCDO();
	UFUNCTION(BlueprintCallable)
		int GetPickupToolTier();
	UFUNCTION(BlueprintCallable)
		APhysicalItem* GetPickupItemDefault();
	UFUNCTION(BlueprintCallable)
		EPhysicalItemMotionState GetMotionState();
	UFUNCTION(BlueprintCallable)
		void SetAttachPhysics(USceneComponent* Component, FName socketName, bool DoWeld);
	UFUNCTION(BlueprintCallable)
		void SetWorldPhysics();
	UFUNCTION(BlueprintCallable)
		void SetPuppetPhysics();
	UFUNCTION(BlueprintCallable)
		void SetIndicatorPhysics();
	UFUNCTION(BlueprintCallable)
		void SetNonSimulatingPhysics();
	UFUNCTION(BlueprintCallable)
		void SetPhysicsState(EPhysicalItemMotionState state, USceneComponent* attachParent, FName socketName, bool weld);
	UFUNCTION(BlueprintCallable)
		int GetSubSlotIndex();
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerTakePossession(APawn* controllingPawn, bool physicalMovement, bool partOfSwap);
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerReleasePossession(UPrimitiveComponent* hitComponent, bool terrainComponent, FVector hitLocation, FVector_NetQuantizeNormal hitNormal);
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerSlotSetItem(FSlotReference itemSlot, int subslotIndex, FSlotReference sourceTransitionSlot, bool useSourceTransform, bool fromTool, bool SlottedDuringInitialization, bool partOfSwap, bool skipBundling);
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerSlotReleaseItem(bool newOwner, bool FromTool, float RandomForce, bool PartOfSwap);
	UFUNCTION(BlueprintCallable)
		void MulticastDroppedInWorld(UPrimitiveComponent* Component, bool terrainComponent, FVector Point, FVector Normal);
	UFUNCTION(BlueprintCallable)
		void MulticastPickedUpFromWorld(bool physicalMovement);
	UFUNCTION(BlueprintCallable)
		void MulticastReleasedFromSlot(bool FromTool, bool newOwner);
	UFUNCTION(BlueprintCallable)
		void MulticastSetFullyEmplaced(FSlotReference Slot, int subslotIndex);
	UFUNCTION(BlueprintCallable)
		bool CanNeverBeSlotted();
	UFUNCTION(BlueprintCallable)
		UWorldGravity* GetGravity();
	UFUNCTION(BlueprintCallable)
		float GetItemTypeDefaultScale(TSubclassOf<APhysicalItem> Type);
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerSlotEmplaceItem(FSlotReference slot, int subslotIndex, bool snapTo, bool weld);
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerSetSlotCardinalDirection(uint8 direction);
	UFUNCTION(BlueprintCallable)
		void OnRep_ItemState();
	UFUNCTION(BlueprintCallable)
		void OnRep_EmplacementData();

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
