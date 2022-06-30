#pragma once
#include "CoreMinimal.h"
#include "EPhysicalItemMotionState.generated.h"

UENUM()
enum class EPhysicalItemMotionState : uint8 {
    Simulating,
    PickedUp,
    Slotted,
    NonSimulating,
    Indicator,
};

