#pragma once
#include "CoreMinimal.h"
#include "EAstroColor.h"
#include "ColorPaletteGameMenuTabBarButton.generated.h"

USTRUCT(BlueprintType)
struct FColorPaletteGameMenuTabBarButton {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    EAstroColor IconColorLastItemUsedState;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    EAstroColor BGColorLastItemUsedState;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    EAstroColor IconColorUnfocusedState;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    EAstroColor BGColorUnfocusedState;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    EAstroColor IconColorFocusState;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    EAstroColor BGColorFocusState;
    
    ASTRO_API FColorPaletteGameMenuTabBarButton();
};

