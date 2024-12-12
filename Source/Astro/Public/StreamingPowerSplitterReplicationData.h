#pragma once
#include "CoreMinimal.h"
#include "EPowerCableConnectionDirection.h"
#include "StreamingPowerSplitterReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerSplitterReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EPowerCableConnectionDirection> PowerCableConnectionDirections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> CableRealPowerValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> CableSplitRatios;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> CablePowerFlowRatio;
    
    ASTRO_API FStreamingPowerSplitterReplicationData();
};

