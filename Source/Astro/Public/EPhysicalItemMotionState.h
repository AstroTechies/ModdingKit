#pragma once
#include "CoreMinimal.h"
#include "EPhysicalItemMotionState.generated.h"

UENUM(BlueprintType)
enum class EPhysicalItemMotionState : uint8 {
    Simulating,
    PickedUp,
    Slotted,
    NonSimulating,
    Indicator,
};

