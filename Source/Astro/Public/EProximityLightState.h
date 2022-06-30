#pragma once
#include "CoreMinimal.h"
#include "EProximityLightState.generated.h"

UENUM()
enum class EProximityLightState {
    Off,
    On,
    Blinking,
    Pinging,
};

