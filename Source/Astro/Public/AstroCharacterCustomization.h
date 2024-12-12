#pragma once
#include "CoreMinimal.h"
#include "AstroCharacterCustomization.generated.h"

class UAstroCharacterHat;
class UAstroCharacterOverlayPattern;
class UAstroCharacterPalette;
class UAstroCharacterSuit;
class UAstroVisorMaterial;

USTRUCT(BlueprintType)
struct ASTRO_API FAstroCharacterCustomization {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsObfuscated: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroCharacterSuit* Suit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroVisorMaterial* VisorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroCharacterPalette* CharacterPalette;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroCharacterOverlayPattern* OverlayPattern;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroCharacterHat* Hat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroCharacterHat* Mask;
    
    FAstroCharacterCustomization();
};

