// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AstroPlatformSpecificCustomizationContent.generated.h"

class UAstroCharacterSuit;
class UAstroVisorMaterial;
class UAstroCharacterPalette;
class UAstroCharacterHat;
class UAstroEmoteDefinition;
class UAnimMontage;
class USkeletalMesh;

USTRUCT(BlueprintType)
struct ASTRO_API FPlatformSpecificEmoteOverrides
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAstroEmoteDefinition* Emote;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<TSoftObjectPtr<USkeletalMesh>, TSoftObjectPtr<UAnimMontage>> SuitSpecificMontages;
};

UCLASS(BlueprintType)
class ASTRO_API UAstroPlatformSpecificCustomizationContent : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroCharacterSuit>> PlatformSuits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroVisorMaterial>> PlatformVisorMaterials;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroCharacterPalette>> PlatformCharacterPalettes;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroCharacterOverlayPattern>> PlatformCharacterOverlayPatterns;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroCharacterHat>> PlatformHats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroCharacterHat>> PlatformMasks;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroPhotoFilter>> PlatformPhotoFilters;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FPlatformSpecificEmoteOverrides> PlatformSuitEmoteOverrides;
};