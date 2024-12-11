#pragma once
#include "CoreMinimal.h"
#include "AstroCustomizationSoftReferences.generated.h"

class UAstroCharacterHat;
class UAstroCharacterOverlayPattern;
class UAstroCharacterPalette;
class UAstroCharacterSuit;
class UAstroVisorMaterial;

USTRUCT(BlueprintType)
struct ASTRO_API FAstroCustomizationSoftReferences {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAstroCharacterSuit> Suit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAstroVisorMaterial> VisorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAstroCharacterPalette> CharacterPalette;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAstroCharacterOverlayPattern> CharacterOverlayPattern;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAstroCharacterHat> Hat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAstroCharacterHat> Mask;
    
    FAstroCustomizationSoftReferences();
};

