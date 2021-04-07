// Fill out your copyright notice in the Description page of Project Settings.


#include "AstroMissionsManager.h"

// Sets default values
AAstroMissionsManager::AAstroMissionsManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAstroMissionsManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAstroMissionsManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


bool AAstroMissionsManager::GetMissionDataBP(FName missionId, FAstroMissionData& outMissionData)
{
	return false;
}

bool AAstroMissionsManager::GetMissionStateBP(FName missionId, FAstroMissionState& outMissionState)
{
	return false;
}

void AAstroMissionsManager::AuthorityRaiseMissionEvent(EAstroMissionObjectiveType objectiveType, TSubclassOf<UItemType> targetType, TSubclassOf<UItemType> secondaryTargetType, const float count, EPlanetIdentifier planet, FString CustomTag)
{

}

void AAstroMissionsManager::AuthorityActivateMission(FName missionId)
{

}

void AAstroMissionsManager::AuthorityCompleteMission(FName missionId)
{

}