// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "HazardTargetingService.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API UHazardTargetingService : public UBTService
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RequireLineOfSight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool NearestTargetOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaximumTargetDistance;
};
