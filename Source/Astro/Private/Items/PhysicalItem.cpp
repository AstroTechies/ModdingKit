// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicalItem.h"


// Sets default values
APhysicalItem::APhysicalItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemComponent = CreateDefaultSubobject<UItemComponent>(TEXT("UItemComponent"));
	EntityLinkComponent = CreateDefaultSubobject<UActorEntityLinkComponent>(TEXT("UActorEntityLinkComponent"));
	TerrainComponent = CreateDefaultSubobject<UTerrainPhysicsComponent>(TEXT("UTerrainPhysicsComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UStaticMeshComponent"));
	GravityComponent = CreateDefaultSubobject<UWorldGravity>(TEXT("UWorldGravity"));
	ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("UClickableComponent"));
	SlotsComponent = CreateDefaultSubobject<USlotsComponent>(TEXT("USlotsComponent"));
	TooltipComponent = CreateDefaultSubobject<UTooltipComponent>(TEXT("UTooltipComponent"));
	ProceduralState = CreateDefaultSubobject<UProceduralStateComponent>(TEXT("UProceduralStateComponent"));
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

