// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTasksComponent.h"
#include "ActionSystem/AstroAction.h"
#include "AstroActionComponent.generated.h"

UENUM()
enum class EAstroActionNetworking : uint8
{
	Networked = 0,
	LocalOwnerOnly = 1,
	LocalSimulatedProxy = 2
};

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASTRO_API UAstroActionComponent : public UGameplayTasksComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		UAstroAction* CreateAction(TSubclassOf<UAstroAction> ActionType);
	UFUNCTION(BlueprintCallable)
		bool StartAction(TSubclassOf<UAstroAction> ActionType);
	UFUNCTION(BlueprintCallable)
		bool StartActionInstance(UAstroAction* action, EAstroActionNetworking Networking);
};
