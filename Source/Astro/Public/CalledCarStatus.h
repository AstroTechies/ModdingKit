#pragma once
#include "CoreMinimal.h"
#include "ERailCarMovementState.h"
#include "CalledCarStatus.generated.h"

USTRUCT(BlueprintType)
struct FCalledCarStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    ERailCarMovementState CarMovementState;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float DistanceFromStation;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float StartingDistanceFromStation;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint8 RecalledFromStationForward: 1;
    
    ASTRO_API FCalledCarStatus();
};

