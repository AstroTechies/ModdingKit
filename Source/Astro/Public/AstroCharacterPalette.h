#pragma once
#include "CoreMinimal.h"
#include "AstroCustomizationItem.h"
#include "AstroSuitColors.h"
#include "AstroCharacterPalette.generated.h"

class UAstroCharacterSuit;
class UMaterialInstanceConstant;

UCLASS(Blueprintable)
class ASTRO_API UAstroCharacterPalette : public UAstroCustomizationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInstanceConstant> PaletteMaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UAstroCharacterSuit*, UMaterialInstanceConstant*> SuitSpecificMaterialOverrides;
    
    UAstroCharacterPalette();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMaterialInstanceConstant* GetMaterialInstanceForSuit(UAstroCharacterSuit* Suit, bool AllowSuitSpecificMaterialOverrides) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FAstroSuitColors GetMaterialColorsForSuit(UAstroCharacterSuit* Suit) const;
    
};

