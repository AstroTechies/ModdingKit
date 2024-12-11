#pragma once
#include "CoreMinimal.h"
#include "EActuatorCableVisualState.generated.h"

UENUM(BlueprintType)
enum class EActuatorCableVisualState : uint8 {
    Off,
    Invalid,
    Highlighted,
    HighlightedDownstream = 4,
};

