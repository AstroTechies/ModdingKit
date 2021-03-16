// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Physics/CustomGravityVolumeComponent.h"
#include "FixedGravityVolumeComponent.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASTRO_API UFixedGravityVolumeComponent : public UCustomGravityVolumeComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BoxExtent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bApplyGravityUpward;
};
