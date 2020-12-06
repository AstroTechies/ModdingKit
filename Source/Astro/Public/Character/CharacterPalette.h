// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterCustomization.h"
#include "Materials/MaterialInstanceConstant.h"
#include "CharacterPalette.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ASTRO_API UAstroCharacterPalette : public UAstroCustomizationItem
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UMaterialInstanceConstant> PaletteMaterialInstance;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TMap<UAstroCharacterSuit *, UMaterialInstanceConstant *, FDefaultSetAllocator, TDefaultMapHashableKeyFuncs<UAstroCharacterSuit *, UMaterialInstanceConstant *, 0> > SuitSpecificMaterialOverrides;

};
