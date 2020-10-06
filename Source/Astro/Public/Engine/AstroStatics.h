// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AstroStatics.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API UAstroStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void JoinToURL(UPARAM(ref) FString& Name, UObject* WorldContextObject);
	
	
};
