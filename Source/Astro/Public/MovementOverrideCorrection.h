#pragma once
#include "CoreMinimal.h"
#include "MovementOverrideNetData.h"
#include "MovementOverrideCorrection.generated.h"

USTRUCT(BlueprintType)
struct FMovementOverrideCorrection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovementOverrideNetData NetData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ErrorCode;
    
    ASTRO_API FMovementOverrideCorrection();
};

