// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AstroPlayStatics.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API UAstroPlayStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static APlayController* GetPlayController(UObject* WorldContextObject, int Index);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static APlayController* GetLocalPlayController(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static AAstroCharacter* GetLocalAstroCharacter(UObject* WorldContextObject);
	
};
