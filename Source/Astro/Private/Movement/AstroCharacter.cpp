// Fill out your copyright notice in the Description page of Project Settings.

#include "AstroCharacter.h"


// Sets default values
AAstroCharacter::AAstroCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAstroCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAstroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AAstroPlanet * AAstroCharacter::GetLocalPlanet()
{
	return nullptr;
}

AAstroPlanet * AAstroCharacter::GetLocalSolarBody()
{
	return nullptr;
}

void AAstroCharacter::AuthoritySetLocalSolarBody(ASolarBody * solarBody)
{

}

void AAstroCharacter::DetachFromSeat(bool bImmediate, bool bForce)
{
}
