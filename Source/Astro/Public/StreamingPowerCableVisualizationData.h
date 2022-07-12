#pragma once
#include "CoreMinimal.h"
#include "ECableConnectionState.h"
#include "StreamingPowerCableVisualizationData.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerCableVisualizationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float FlowSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ConsumptionRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float GenerationRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECableConnectionState CableConnectionState;
    
    ASTRO_API FStreamingPowerCableVisualizationData();
};

