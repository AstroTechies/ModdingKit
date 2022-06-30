#pragma once
#include "CoreMinimal.h"
#include "ETooltipProximityState.generated.h"

UENUM()
enum class ETooltipProximityState : uint8 {
    WithinPrimaryProximity,
    WithinSecondaryProximity,
    WithinDetailsProximity,
    OutOfRange,
};

