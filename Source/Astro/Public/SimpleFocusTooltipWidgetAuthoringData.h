#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "EAstroGameMenuTutorialSlideDeckKey.h"
#include "SimpleFocusTooltipWidgetAuthoringData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FSimpleFocusTooltipWidgetAuthoringData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SubTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BadgeColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ResourceObjectBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseSquareBadgeBackground;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroGameMenuTutorialSlideDeckKey OpenAstropediaDeck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroGameMenuTutoriaSlideCardKey OpenAstropediaCard;
    
    ASTRO_API FSimpleFocusTooltipWidgetAuthoringData();
};

