// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicalItem.h"


// Sets default values
APhysicalItem::APhysicalItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemComponent = CreateDefaultSubobject<UItemComponent>(TEXT("ItemComponent"));
	EntityLinkComponent = CreateDefaultSubobject<UActorEntityLinkComponent>(TEXT("EntityLinkComponent"));
	TerrainComponent = CreateDefaultSubobject<UTerrainPhysicsComponent>(TEXT("Terrain Physics"));
	GravityComponent = CreateDefaultSubobject<UWorldGravity>(TEXT("WorldGravity"));
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

