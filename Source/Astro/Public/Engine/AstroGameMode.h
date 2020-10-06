// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "AstroGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API AAstroGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector DefaultSpawnLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator DefaultSpawnRotation;
	
};
