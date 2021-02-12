// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveComponent.h"

// Sets default values for this component's properties
UExplosiveComponent::UExplosiveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UExplosiveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UExplosiveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UExplosiveComponent::Detonate()
{

}

void UExplosiveComponent::SetDetonationTimer(float DeltaTime)
{

}

void UExplosiveComponent::SetDetonationTimerPaused(bool bIsPaused)
{

}

void UExplosiveComponent::CancelDetonationTimer()
{

}

void UExplosiveComponent::DoExplosionDeformation(FVector location, float radius)
{

}

void UExplosiveComponent::DoBlastDamage(FVector location, float radius, float intensity)
{

}

void UExplosiveComponent::DamageActor(AActor* actor, FVector direction, float intensity)
{

}

bool UExplosiveComponent::ExplosiveDestroyActor(AActor* ToDestroy)
{
	return false;
}