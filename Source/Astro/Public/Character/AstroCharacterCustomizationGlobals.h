// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AstroCharacterCustomizationGlobals.generated.h"

class UAstroCharacterSuit;
class UAstroVisorMaterial;
class UAstroCharacterPalette;
class UAstroCharacterHat;

USTRUCT(BlueprintType)
struct ASTRO_API FAstroCharacterCustomization
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAstroCharacterSuit* Suit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAstroVisorMaterial* VisorMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAstroCharacterPalette* CharacterPalette;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAstroCharacterOverlayPattern* OverlayPattern;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAstroCharacterHat* Hat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAstroCharacterHat* Mask;
};

UCLASS(BlueprintType)
class ASTRO_API UAstroCharacterCustomizationGlobals : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroCharacterSuit>> Suits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroVisorMaterial>> VisorMaterials;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroCharacterPalette>> CharacterPalettes;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroCharacterOverlayPattern>> CharacterOverlayPatterns;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroCharacterHat>> Hats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroCharacterHat>> Masks;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroPhotoFilter>> PhotoFilters;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAstroCharacterCustomization DefaultCharacterCustomization;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UAstroCharacterPalette*> DefaultCharacterPalettesByPlayerIndex;
};