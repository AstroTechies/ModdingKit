// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterCustomization.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "CharacterSuit.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ASTRO_API UAstroCharacterSuit : public UAstroCustomizationItem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UAnimInstance> AnimationBlueprintType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UAnimInstance> TitleDummyAnimationBlueprintType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<UAnimMontage> PointMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName SuitAudioType;


};
