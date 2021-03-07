// Fill out your copyright notice in the Description page of Project Settings.

#include "AstroCharacter.h"
#include "GameFramework/PlayerController.h"

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

APlayController* AAstroCharacter::GetPlayController()
{
	return nullptr;
}

AAstroPlanet* AAstroCharacter::GetLocalPlanet()
{
	return nullptr;
}

AAstroPlanet* AAstroCharacter::GetLocalSolarBody()
{
	return nullptr;
}

void AAstroCharacter::AuthoritySetLocalSolarBody(ASolarBody * solarBody)
{

}

void AAstroCharacter::DetachFromSeat(bool bImmediate, bool bForce)
{

}

FString AAstroCharacter::GetOnlinePlayerName()
{
	return "";
}

UAstroCharacterHat* AAstroCharacter::GetCharacterHat(ECharacterHatCategory category)
{
	return nullptr;
}

UAstroCharacterPalette* AAstroCharacter::GetCharacterPalette()
{
	return nullptr;
}

UAstroCharacterSuit* AAstroCharacter::GetCharacterSuit()
{
	return nullptr;
}

UAstroVisorMaterial* AAstroCharacter::GetCharacterVisorMaterial()
{
	return nullptr;
}

ABackpack* AAstroCharacter::GetBackpack()
{
	return nullptr;
}