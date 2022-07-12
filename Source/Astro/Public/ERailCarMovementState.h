#pragma once
#include "CoreMinimal.h"
#include "ERailCarMovementState.generated.h"

UENUM(BlueprintType)
enum class ERailCarMovementState : uint8 {
    Off,
    Moving,
    Blocked,
    NoPower,
    LowPower,
};

