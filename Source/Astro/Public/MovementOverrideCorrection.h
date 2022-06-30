#pragma once
#include "CoreMinimal.h"
#include "MovementOverrideNetData.h"
#include "MovementOverrideCorrection.generated.h"

USTRUCT(BlueprintType)
struct FMovementOverrideCorrection {
    GENERATED_BODY()
public:
    UPROPERTY()
    FMovementOverrideNetData NetData;
    
    UPROPERTY()
    uint8 ErrorCode;
    
    ASTRO_API FMovementOverrideCorrection();
};

