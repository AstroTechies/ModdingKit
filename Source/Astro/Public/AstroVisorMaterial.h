#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AstroCustomizationItem.h"
#include "AstroVisorMaterial.generated.h"

class UAstroCharacterSuit;
class UMaterialInterface;

UCLASS(Blueprintable)
class ASTRO_API UAstroVisorMaterial : public UAstroCustomizationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* VisorMaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor visorColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UAstroCharacterSuit*, UMaterialInterface*> SuitSpecificMaterialOverrides;
    
    UAstroVisorMaterial();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMaterialInterface* GetMaterialInstanceForSuit(UAstroCharacterSuit* Suit) const;
    
};

