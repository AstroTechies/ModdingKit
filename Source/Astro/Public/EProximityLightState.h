#pragma once
#include "CoreMinimal.h"
#include "EProximityLightState.generated.h"

UENUM(BlueprintType)
enum class EProximityLightState : uint8 {
    Off,
    On,
    Blinking,
    Pinging,
};

