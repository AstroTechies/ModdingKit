// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Character/CharacterCustomization.h"
#include "AstroEmoteDefinition.generated.h"

UENUM(BlueprintType)
enum class EEmoteType : uint8 {
	Gesture = 0,
	Dance = 1
};

UCLASS(BlueprintType)
class ASTRO_API UAstroEmoteDefinition : public UAstroCustomizationItem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEmoteType EmoteType;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UAstroPlayMontageAction> EmoteActionTypeOverride;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<UAnimMontage> DefaultMontage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<TSoftObjectPtr<USkeletalMesh>,TSoftObjectPtr<UAnimMontage>> SuitSpecificMontages;*/
};