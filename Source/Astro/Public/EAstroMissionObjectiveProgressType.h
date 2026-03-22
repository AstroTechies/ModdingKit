#pragma once
#include "CoreMinimal.h"
#include "EAstroMissionObjectiveProgressType.generated.h"

UENUM(BlueprintType)
enum class EAstroMissionObjectiveProgressType : uint8 {
    Increment,
    HighWater,
    Set,
};

