#pragma once
#include "CoreMinimal.h"
#include "ProgressPredictionData.generated.h"

USTRUCT(BlueprintType)
struct FProgressPredictionData {
    GENERATED_BODY()
public:
    UPROPERTY()
    int32 LocalCacheItemDriveProgressDelta;
    
    UPROPERTY()
    int32 ReportedItemDriveProgressDelta;
    
    ASTRO_API FProgressPredictionData();
};

