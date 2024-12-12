#pragma once
#include "CoreMinimal.h"
#include "EStationStopState.generated.h"

UENUM(BlueprintType)
enum class EStationStopState : uint8 {
    EInert,
    EStopUncalled,
    EStopAll,
};

