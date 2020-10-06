// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AstroPlanet.h"
#include "PlanetStatics.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API UPlanetStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static AAstroPlanet* GetPlanet(UPARAM(ref) AActor* actor, bool bBoundsCheck);
	
	
};
