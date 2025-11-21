#pragma once
#include "CoreMinimal.h"
#include "AstroCustomizationItem.h"
#include "CharacterHatPerSuitModifiers.h"
#include "ECharacterHatCategory.h"
#include "AstroCharacterHat.generated.h"

class UAstroCharacterHat;
class UAstroCharacterPalette;
class UAstroCharacterSuit;
class UMaterialInstanceConstant;
class UMaterialInterface;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASTRO_API UAstroCharacterHat : public UAstroCustomizationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInstanceConstant> MaterialOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UAstroCharacterSuit*, FCharacterHatPerSuitModifiers> SuitSpecificModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 AcceptSuitColors: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 AcceptSuitMaterial: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECharacterHatCategory HatCategory;
    
    UAstroCharacterHat();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FCharacterHatPerSuitModifiers GetHatModifierForSuit(UAstroCharacterSuit* Suit, bool allowSuitSpecificOverrides) const;
    
    UFUNCTION(BlueprintCallable)
    static void ApplyToMesh(UStaticMeshComponent* targetMesh, UAstroCharacterSuit* Suit, UAstroCharacterHat* hatDef, UAstroCharacterPalette* Palette, bool bObfuscated, UMaterialInterface* ObfuscatedMaterial);
    
};

