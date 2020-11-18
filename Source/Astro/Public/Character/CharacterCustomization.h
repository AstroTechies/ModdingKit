// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterCustomization.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ASTRO_API UAstroCustomizationItem : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText DescriptionText;
};

UCLASS(BlueprintType)
class ASTRO_API UAstroCharacterHat : public UAstroCustomizationItem
{
	GENERATED_BODY()
};

UCLASS(BlueprintType)
class ASTRO_API UAstroCharacterPalette : public UAstroCustomizationItem
{
	GENERATED_BODY()
};

UCLASS(BlueprintType)
class ASTRO_API UAstroCharacterSuit : public UAstroCustomizationItem
{
	GENERATED_BODY()
};

UCLASS(BlueprintType)
class ASTRO_API UAstroVisorMaterial : public UAstroCustomizationItem
{
	GENERATED_BODY()
};
