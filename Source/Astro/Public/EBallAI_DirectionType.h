#pragma once
#include "CoreMinimal.h"
#include "EBallAI_DirectionType.generated.h"

UENUM()
enum class EBallAI_DirectionType : uint8 {
    Random,
    Uphill,
    EBallAI_MAX UMETA(Hidden),
};

