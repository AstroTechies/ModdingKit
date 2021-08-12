// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayController.h"


// Sets default values
APlayController::APlayController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayController::SetFreeCam()
{

}

FString APlayController::RunScript(FString script)
{
	return FString();
}

void APlayController::Ping()
{

}

void APlayController::SetCurrentSpawnPoint(AActor* spawn)
{

}

AAstroCharacter* APlayController::GetAstroCharacter()
{
	return nullptr;
}

USceneComponent* APlayController::GetSpawnLocation()
{
	return nullptr;
}

UCameraComponent* APlayController::GetCamera()
{
	return nullptr;
}

FRotator APlayController::GetCameraRotation()
{
	return FRotator();
}

FVector APlayController::GetCameraLocation()
{
	return FVector();
}

void APlayController::OnCharacterLocalSolarBodyChanged(ASolarBody* newLocalSolarBody)
{

}

UTooltipManager* APlayController::GetTooltipManager()
{
	return nullptr;
}

void APlayController::TeleportToCursor()
{

}