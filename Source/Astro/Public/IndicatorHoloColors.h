#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IndicatorHoloColors.generated.h"

USTRUCT(BlueprintType)
struct FIndicatorHoloColors {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor FillColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor RimColor;
    
    ASTRO_API FIndicatorHoloColors();
};

