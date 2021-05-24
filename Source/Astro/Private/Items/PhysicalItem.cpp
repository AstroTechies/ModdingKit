// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicalItem.h"

// Sets default values
APhysicalItem::APhysicalItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemComponent = CreateDefaultSubobject<UItemComponent>(TEXT("Item"));
	EntityLinkComponent = CreateDefaultSubobject<UActorEntityLinkComponent>(TEXT("EntityLinkComponent"));
	TerrainComponent = CreateDefaultSubobject<UTerrainPhysicsComponent>(TEXT("Terrain Physics"));
	GravityComponent = CreateDefaultSubobject<UWorldGravity>(TEXT("Gravity"));
	ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("ItemClickableComponent"));
	SlotsComponent = CreateDefaultSubobject<USlotsComponent>(TEXT("SlotsComponent"));
	TooltipComponent = CreateDefaultSubobject<UTooltipComponent>(TEXT("TooltipComponent"));
	ProceduralState = CreateDefaultSubobject<UProceduralStateComponent>(TEXT("ProceduralStateComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void APhysicalItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhysicalItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APhysicalItem::Movable(int ToolTier)
{
	return false;
}

void APhysicalItem::StartItemInWorld()
{

}

UChildSlotComponent* APhysicalItem::GetBodySlotLegacy_Implementation()
{
	return nullptr;
}

FSlotReference APhysicalItem::GetBodySlot()
{
	return FSlotReference();
}

FTransform APhysicalItem::PlacementTransform(FHitResult Hit)
{
	return FTransform();
}

void APhysicalItem::DropInWorld(UPrimitiveComponent* Component, bool terrainComponent, FVector Point, FVector Normal)
{

}

void APhysicalItem::PickUpFromWorld(bool physicalMovement)
{

}

FTransform APhysicalItem::GetBaseLocation()
{
	return FTransform();
}

FText APhysicalItem::GetItemName()
{
	return FText();
}

float APhysicalItem::GetPrinterHeight()
{
	return 0;
}

TSubclassOf<UItemType> APhysicalItem::GetFunctionalItemTypeClass()
{
	TSubclassOf<UItemType> x;
	return x;
}

TSubclassOf<UItemType> APhysicalItem::GetStoredSubItemTypeClass()
{
	TSubclassOf<UItemType> x;
	return x;
}

TSubclassOf<UItemType> APhysicalItem::GetLiteralItemTypeClass()
{
	TSubclassOf<UItemType> x;
	return x;
}

UItemType* APhysicalItem::GetFunctionalItemTypeCDO()
{
	return nullptr;
}

UItemType* APhysicalItem::GetStoredSubItemTypeCDO()
{
	return nullptr;
}

UItemType* APhysicalItem::GetLiteralItemTypeCDO()
{
	return nullptr;
}

int APhysicalItem::GetPickupToolTier()
{
	return 0;
}

APhysicalItem* APhysicalItem::GetPickupItemDefault()
{
	return nullptr;
}

EPhysicalItemMotionState APhysicalItem::GetMotionState()
{
	return EPhysicalItemMotionState::Simulating;
}

void APhysicalItem::SetAttachPhysics(USceneComponent* Component, FName socketName, bool DoWeld)
{

}

void APhysicalItem::SetWorldPhysics()
{

}

void APhysicalItem::SetPuppetPhysics()
{

}

void APhysicalItem::SetIndicatorPhysics()
{

}

void APhysicalItem::SetNonSimulatingPhysics()
{

}

void APhysicalItem::SetPhysicsState(EPhysicalItemMotionState state, USceneComponent* attachParent, FName socketName, bool weld)
{

}

int APhysicalItem::GetSubSlotIndex()
{
	return 0;
}

void APhysicalItem::ServerTakePossession_Implementation(APawn* controllingPawn, bool physicalMovement, bool partOfSwap)
{

}

bool APhysicalItem::ServerTakePossession_Validate(APawn* controllingPawn, bool physicalMovement, bool partOfSwap)
{
	return true;
}

void APhysicalItem::ServerReleasePossession_Implementation(UPrimitiveComponent* hitComponent, bool terrainComponent, FVector hitLocation, FVector_NetQuantizeNormal hitNormal)
{

}

bool APhysicalItem::ServerReleasePossession_Validate(UPrimitiveComponent* hitComponent, bool terrainComponent, FVector hitLocation, FVector_NetQuantizeNormal hitNormal)
{
	return true;
}

void APhysicalItem::ServerSlotSetItem_Implementation(FSlotReference itemSlot, int subslotIndex, FSlotReference sourceTransitionSlot, bool useSourceTransform, bool fromTool, bool SlottedDuringInitialization, bool partOfSwap, bool skipBundling)
{

}

bool APhysicalItem::ServerSlotSetItem_Validate(FSlotReference itemSlot, int subslotIndex, FSlotReference sourceTransitionSlot, bool useSourceTransform, bool fromTool, bool SlottedDuringInitialization, bool partOfSwap, bool skipBundling)
{
	return true;
}

void APhysicalItem::ServerSlotReleaseItem_Implementation(bool newOwner, bool FromTool, float RandomForce, bool PartOfSwap)
{

}

bool APhysicalItem::ServerSlotReleaseItem_Validate(bool newOwner, bool FromTool, float RandomForce, bool PartOfSwap)
{
	return true;
}

void APhysicalItem::PlacedInSlot_Implementation(FSlotReference Slot, bool FromTool, bool SlottedDuringInitialization)
{

}

void APhysicalItem::DroppedInWorld_Implementation(UPrimitiveComponent* Component, bool terrainComponent, FVector Point, FVector Normal)
{

}

void APhysicalItem::PickedUpFromWorld_Implementation()
{

}

void APhysicalItem::ReleasedFromSlot_Implementation(bool FromTool, bool newOwner)
{

}

void APhysicalItem::MulticastDroppedInWorld_Implementation(UPrimitiveComponent* Component, bool terrainComponent, FVector Point, FVector Normal)
{

}

void APhysicalItem::MulticastPickedUpFromWorld_Implementation(bool physicalMovement)
{

}

void APhysicalItem::MulticastReleasedFromSlot_Implementation(bool FromTool, bool newOwner)
{

}

void APhysicalItem::MulticastSetFullyEmplaced_Implementation(FSlotReference Slot, int subslotIndex)
{

}

bool APhysicalItem::CanNeverBeSlotted()
{
	return false;
}

UWorldGravity* APhysicalItem::GetGravity()
{
	return nullptr;
}

float APhysicalItem::GetItemTypeDefaultScale(TSubclassOf<APhysicalItem> Type)
{
	return 0;
}

void APhysicalItem::ServerSlotEmplaceItem_Implementation(FSlotReference slot, int subslotIndex, bool snapTo, bool weld)
{

}

bool APhysicalItem::ServerSlotEmplaceItem_Validate(FSlotReference slot, int subslotIndex, bool snapTo, bool weld)
{
	return true;
}

void APhysicalItem::ServerSetSlotCardinalDirection_Implementation(uint8 direction)
{

}

bool APhysicalItem::ServerSetSlotCardinalDirection_Validate(uint8 direction)
{
	return true;
}

void APhysicalItem::OnRep_ItemState()
{

}

void APhysicalItem::OnRep_EmplacementData()
{

}