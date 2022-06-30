#pragma once
#include "CoreMinimal.h"
#include "EActuatorCableVisualState.generated.h"

UENUM()
enum class EActuatorCableVisualState {
    Off,
    Invalid,
    Highlighted,
    HighlightedDownstream = 0x4,
};

