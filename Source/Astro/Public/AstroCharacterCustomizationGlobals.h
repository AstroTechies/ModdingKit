#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AstroCharacterCustomization.h"
#include "AstroCharacterCustomizationGlobals.generated.h"

class UAstroCharacterHat;
class UAstroCharacterOverlayPattern;
class UAstroCharacterPalette;
class UAstroCharacterSuit;
class UAstroPhotoFilter;
class UAstroVisorMaterial;

UCLASS(Blueprintable)
class ASTRO_API UAstroCharacterCustomizationGlobals : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroCharacterSuit>> Suits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroVisorMaterial>> VisorMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroCharacterPalette>> CharacterPalettes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroCharacterOverlayPattern>> CharacterOverlayPatterns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroCharacterHat>> Hats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroCharacterHat>> Masks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroPhotoFilter>> PhotoFilters;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroCharacterCustomization DefaultCharacterCustomization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroCharacterPalette*> DefaultCharacterPalettesByPlayerIndex;
    
    UAstroCharacterCustomizationGlobals();

};

