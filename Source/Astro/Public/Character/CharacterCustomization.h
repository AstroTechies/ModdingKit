// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/Texture2D.h"
#include "CharacterCustomization.generated.h"



UENUM()
enum class ECharacterCustomizationVisibility : uint8 {
	HiddenToAll = 0,
	HiddenUnlessUnlocked = 1,
	ObfuscatedUnlessUnlocked = 2,
	VisibleButUnlockRequired = 3,
	AvailableToAll = 4
};

UENUM()
enum class EMicroTxnStoreTileTypes : uint8 {
	None = 0,
	Normal = 1,
	Featured = 2,
	Tall = 3,
	Wide = 4,
	Large = 5
};

UCLASS(BlueprintType)
class ASTRO_API UAstroCustomizationItem : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DisplayName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DescriptionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECharacterCustomizationVisibility DisplayVisibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText UnlockConditionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsNonAchievementUnlock = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> TileIconTexture;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> TileItemTexture;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> TileBackgroundTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> FeaturedTileBackgroundTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMicroTxnStoreTileTypes TileType;
};
