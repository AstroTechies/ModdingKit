// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CustomGravityVolumeComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API UCustomGravityVolumeComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void OnComponentEnteredCustomGravityVolume(UPrimitiveComponent* volumeComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int otherBodyIndex, bool bFromSweep, FHitResult sweepResult);
	UFUNCTION(BlueprintCallable)
		void OnComponentExitedCustomGravityVolume(UPrimitiveComponent* volumeComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int otherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName GravityVolumeComponentName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GravityStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPrimitiveComponent* GravityVolume;
		
};
