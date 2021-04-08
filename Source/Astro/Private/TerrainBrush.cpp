// Fill out your copyright notice in the Description page of Project Settings.


#include "TerrainBrush.h"

// Sets default values
ATerrainBrush::ATerrainBrush()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATerrainBrush::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATerrainBrush::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

