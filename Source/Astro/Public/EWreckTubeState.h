#pragma once
#include "CoreMinimal.h"
#include "EWreckTubeState.generated.h"

UENUM(BlueprintType)
enum class EWreckTubeState : uint8 {
    Unloaded,
    Loaded,
    Restocking,
    Empty,
    Busy,
};

