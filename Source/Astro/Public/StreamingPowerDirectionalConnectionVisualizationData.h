#pragma once
#include "CoreMinimal.h"
#include "StreamingPowerDirectionalConnectionVisualizationData.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerDirectionalConnectionVisualizationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LineSaturationRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PowerOverrideSplitRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PowerAmount;
    
    ASTRO_API FStreamingPowerDirectionalConnectionVisualizationData();
};

