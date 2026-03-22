#pragma once
#include "CoreMinimal.h"
#include "StreamingPowerNodeVisualizationData.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerNodeVisualizationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConsumerDemandFulfilmentRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GenerationRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SurplusRatio;
    
    ASTRO_API FStreamingPowerNodeVisualizationData();
};

