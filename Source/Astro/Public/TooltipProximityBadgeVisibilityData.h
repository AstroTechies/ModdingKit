#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include "TooltipProximityBadgeVisibilityData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FTooltipProximityBadgeVisibilityData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    float BadgeProximityRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    float DetailsProximityRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    uint8 bHasSecondaryLongDistanceBadge: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    uint8 bSecondaryLongDistanceBadgeAlwaysVisible: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    float SecondaryLongDistanceBadgeProximityRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    FLinearColor SecondaryLongDistanceBadgeColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    UObject* ResourceObjectSecondaryLongDistanceBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    UObject* ResourceObjectSecondaryLongDistanceBadgeBackground;
    
    ASTRO_API FTooltipProximityBadgeVisibilityData();
};

