// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AstroPlayerController.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FDSTravelInitiatedDelegate, bool, Success); // might be wrong

/**
 * 
 */
UCLASS()
class ASTRO_API AAstroPlayerController : public APlayerController
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
		void TravelToDedicatedServerByURL(FString serverURL, FString password, FDSTravelInitiatedDelegate TravelInitiated);
};
