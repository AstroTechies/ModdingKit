// Fill out your copyright notice in the Description page of Project Settings.

#include "TerrainPhysicsComponent.h"


// Sets default values for this component's properties
UTerrainPhysicsComponent::UTerrainPhysicsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTerrainPhysicsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTerrainPhysicsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTerrainPhysicsComponent::SetWorldPhysics()
{

}

void UTerrainPhysicsComponent::SetBuryPhysics()
{

}

void UTerrainPhysicsComponent::SetPickupPhysics()
{

}

bool UTerrainPhysicsComponent::GetIsBuried()
{
	return false;
}

void UTerrainPhysicsComponent::SetIsBuried(bool NewIsBuried)
{

}

bool UTerrainPhysicsComponent::IsTerrainBuried()
{
	return false;
}