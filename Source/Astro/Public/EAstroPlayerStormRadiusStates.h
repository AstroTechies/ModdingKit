#pragma once
#include "CoreMinimal.h"
#include "EAstroPlayerStormRadiusStates.generated.h"

UENUM(BlueprintType)
enum class EAstroPlayerStormRadiusStates : uint8 {
    OutsideStorm,
    InsideStorm,
    InsideEye,
};

