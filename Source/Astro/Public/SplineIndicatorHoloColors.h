#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SplineIndicatorHoloColors.generated.h"

USTRUCT(BlueprintType)
struct FSplineIndicatorHoloColors {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor FillColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor RimColor;
    
    ASTRO_API FSplineIndicatorHoloColors();
};

