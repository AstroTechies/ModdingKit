#pragma once
#include "CoreMinimal.h"
#include "PlatformSpecificEmoteOverrides.h"
#include "CombinedRuntimeCustomizationContent.generated.h"

class UAstroCharacterHat;
class UAstroCharacterOverlayPattern;
class UAstroCharacterPalette;
class UAstroCharacterSuit;
class UAstroPhotoFilter;
class UAstroVisorMaterial;

USTRUCT(BlueprintType)
struct FCombinedRuntimeCustomizationContent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroCharacterSuit>> Suits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroVisorMaterial>> VisorMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroCharacterPalette>> CharacterPalettes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroCharacterOverlayPattern>> CharacterOverlayPatterns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroCharacterHat>> Hats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroCharacterHat>> Masks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroPhotoFilter>> PhotoFilters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPlatformSpecificEmoteOverrides> PlatformSuitEmoteOverrides;
    
    ASTRO_API FCombinedRuntimeCustomizationContent();
};

