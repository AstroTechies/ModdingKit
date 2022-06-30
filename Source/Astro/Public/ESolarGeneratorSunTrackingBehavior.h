#pragma once
#include "CoreMinimal.h"
#include "ESolarGeneratorSunTrackingBehavior.generated.h"

UENUM()
enum class ESolarGeneratorSunTrackingBehavior : uint8 {
    Pivot,
    LocalRollAxis,
    LocalPitchAxis,
    LocalYawAxis,
};

