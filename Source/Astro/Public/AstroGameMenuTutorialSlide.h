#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuTutorialSlide.generated.h"

class UUserWidget;

USTRUCT(BlueprintType)
struct FAstroGameMenuTutorialSlide {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UUserWidget> TutorialSlideWidget;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UUserWidget> GamepadOverrideTutorialSlideWidget;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    FText SlideDescriptiveName;
    
    ASTRO_API FAstroGameMenuTutorialSlide();
};

