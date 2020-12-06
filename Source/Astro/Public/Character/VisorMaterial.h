// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterCustomization.h"
#include "Character/CharacterSuit.h"
#include "VisorMaterial.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API UAstroVisorMaterial : public UAstroCustomizationItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* VisorMaterialInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor VisorColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<UAstroCharacterSuit*, UMaterialInterface*> SuitSpecificMaterialOverrides;

};
