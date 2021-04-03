// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "AstroSettings.generated.h"

class AAstroPlanet;
class ASolarBody;
class UAstroMissionDataAsset;

UCLASS()
class ASTRO_API AAstroSettings : public AWorldSettings
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static AAstroSettings* GetAstroSettings(AActor* Actor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString OutroCinematicAudioEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName OutroCinematicMusicState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor *> CinematicTerrainResolutionPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AAstroPlanet *> PlanetsToReseedForCinematic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector GateStationSpawnLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ASolarBody* GateStationOrbitingBody;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GateStationOrbitDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector GateStationOrbitDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector GateStationOrbitAxis;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UAstroMissionDataAsset *> MissionData;
};
