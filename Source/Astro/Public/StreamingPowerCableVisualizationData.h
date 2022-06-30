#pragma once
#include "CoreMinimal.h"
#include "ECableConnectionState.h"
#include "StreamingPowerCableVisualizationData.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerCableVisualizationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient, meta=(AllowPrivateAccess=true))
    float FlowSpeed;
    
    UPROPERTY(BlueprintReadWrite, Transient, meta=(AllowPrivateAccess=true))
    float ConsumptionRatio;
    
    UPROPERTY(BlueprintReadWrite, Transient, meta=(AllowPrivateAccess=true))
    float GenerationRatio;
    
    UPROPERTY(BlueprintReadWrite, Transient, meta=(AllowPrivateAccess=true))
    ECableConnectionState CableConnectionState;
    
    ASTRO_API FStreamingPowerCableVisualizationData();
};

