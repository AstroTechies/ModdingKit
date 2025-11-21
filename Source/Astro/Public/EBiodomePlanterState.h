#pragma once
#include "CoreMinimal.h"
#include "EBiodomePlanterState.generated.h"

UENUM(BlueprintType)
enum class EBiodomePlanterState : uint8 {
    Inactive,
    Firing,
    Planting,
    Reloading,
    WaitingForSeed,
    ResourceSlotsEmpty,
    WaitingForTargetSlot,
    LowPower,
};

