// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SolarBody.h"
#include "AstroPlanet.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API AAstroPlanet : public ASolarBody
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
		// Returns a vector that points North
		FVector GetNorthVector();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		float GetRadius();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* LowRezClouds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* LowRezProxyClouds;
};
