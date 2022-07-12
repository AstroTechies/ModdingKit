#pragma once
#include "CoreMinimal.h"
#include "ProgressPredictionData.generated.h"

USTRUCT(BlueprintType)
struct FProgressPredictionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LocalCacheItemDriveProgressDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ReportedItemDriveProgressDelta;
    
    ASTRO_API FProgressPredictionData();
};

