#pragma once
#include "CoreMinimal.h"
#include "ERiftOrbState.generated.h"

UENUM(BlueprintType)
enum class ERiftOrbState : uint8 {
    Scattering,
    Hidden,
    Standby,
    InPosition,
    AlignmentSequence,
    FollowingPlayer,
    ReturningToRift,
    FollowingRift,
    GameComplete,
};

