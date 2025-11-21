#pragma once
#include "CoreMinimal.h"
#include "EShuttleSequenceState.generated.h"

UENUM(BlueprintType)
enum class EShuttleSequenceState : uint8 {
    Orbit,
    Transition,
    OrbitAroundDestination,
    Landed,
    Invalid,
};

