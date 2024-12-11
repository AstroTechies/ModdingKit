#pragma once
#include "CoreMinimal.h"
#include "EDroneFlightState.generated.h"

UENUM(BlueprintType)
enum class EDroneFlightState : uint8 {
    Docked,
    Docking,
    Launching,
    FlyingDroneCamDroneControls,
    FlyingDroneCamAstroControls,
    FlyingAstroCamAstroControls,
};

