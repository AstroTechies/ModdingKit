// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AstroCharacter.h"
#include "Character/CharacterCustomization.h"
#include "Character/Charactersuit.h"
#include "Character/CharacterPalette.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Containers/ContainerAllocationPolicies.h"
#include "CharacterHat.generated.h"


UENUM()
enum class ECharacterHatCategory : uint8 {
	Head = 0,
	Mask = 1,
};

USTRUCT(BlueprintType)
struct ASTRO_API FCharacterHatPerSuitModifiers
{
	GENERATED_USTRUCT_BODY();

public:

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform Offset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UMaterialInstanceConstant> MaterialOverride;

};

/**
 * 
 */
UCLASS(BlueprintType)
class ASTRO_API UAstroCharacterHat : public UAstroCustomizationItem
{
	GENERATED_BODY()

	public:
		virtual void ApplyToMesh(UStaticMeshComponent* targetMesh, UAstroCharacterSuit* suit, UAstroCharacterHat* hatDef, UAstroCharacterPalette* palette);

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<UStaticMesh> StaticMesh;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
	    TMap<UAstroCharacterSuit*, FCharacterHatPerSuitModifiers> SuitSpecificModifiers;
		
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool AcceptSuitColors;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool AcceptSuitMaterial;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ECharacterHatCategory HatCategory;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<UMaterialInstanceConstant> MaterialOverride;

};
