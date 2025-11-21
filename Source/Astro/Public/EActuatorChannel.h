#pragma once
#include "CoreMinimal.h"
#include "EActuatorChannel.generated.h"

UENUM(BlueprintType)
enum class EActuatorChannel : uint8 {
    None,
    A,
    B,
    C,
    MiddleA,
    MiddleB,
    MiddleC,
};

