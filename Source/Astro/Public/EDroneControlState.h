#pragma once
#include "CoreMinimal.h"
#include "EDroneControlState.generated.h"

UENUM(BlueprintType)
enum class EDroneControlState : uint8 {
    NotUsingDrone,
    ControllingDrone,
    DroneCamAstroControls,
    ControllingAstroWithDroneDeployed,
};

