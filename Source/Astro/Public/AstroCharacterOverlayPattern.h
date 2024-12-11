#pragma once
#include "CoreMinimal.h"
#include "AstroCustomizationItem.h"
#include "AstroCharacterOverlayPattern.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class ASTRO_API UAstroCharacterOverlayPattern : public UAstroCustomizationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TileFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* PatternTexture;
    
    UAstroCharacterOverlayPattern();

};

