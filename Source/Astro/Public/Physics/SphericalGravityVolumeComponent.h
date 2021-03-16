// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Physics/CustomGravityVolumeComponent.h"
#include "SphericalGravityVolumeComponent.generated.h"

UCLASS(BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASTRO_API USphericalGravityVolumeComponent : public UCustomGravityVolumeComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SphereRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bApplyGravityOutward;
};