// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AstroPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API AAstroPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
		// The PlayFab ID of a player. Seemingly only accessible on dedicated servers.
		FString BackendPlayerId;
};
