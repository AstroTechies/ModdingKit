// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Physics/CustomGravityVolumeComponent.h"
#include "CylindricalGravityVolumeComponent.generated.h"

UCLASS(BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASTRO_API UCylindricalGravityVolumeComponent : public UCustomGravityVolumeComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CylinderRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CylinderHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bApplyGravityOutward;
};