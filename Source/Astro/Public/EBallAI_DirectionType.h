#pragma once
#include "CoreMinimal.h"
#include "EBallAI_DirectionType.generated.h"

UENUM(BlueprintType)
enum class EBallAI_DirectionType : uint8 {
    Random,
    Uphill,
};

