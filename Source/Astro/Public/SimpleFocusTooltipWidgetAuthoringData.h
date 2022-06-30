#pragma once
#include "CoreMinimal.h"
#include "EAstroGameMenuTutorialSlideDeckKey.h"
#include "UObject/NoExportTypes.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "SimpleFocusTooltipWidgetAuthoringData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FSimpleFocusTooltipWidgetAuthoringData {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FText Title;
    
    UPROPERTY(EditDefaultsOnly)
    FText SubTitle;
    
    UPROPERTY(EditDefaultsOnly)
    FText Description;
    
    UPROPERTY(EditDefaultsOnly)
    FLinearColor BadgeColor;
    
    UPROPERTY(EditDefaultsOnly)
    UObject* ResourceObjectBadge;
    
    UPROPERTY(EditDefaultsOnly)
    bool UseSquareBadgeBackground;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroGameMenuTutorialSlideDeckKey OpenAstropediaDeck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroGameMenuTutoriaSlideCardKey OpenAstropediaCard;
    
    ASTRO_API FSimpleFocusTooltipWidgetAuthoringData();
};

