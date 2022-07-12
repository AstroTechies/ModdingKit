#pragma once
#include "CoreMinimal.h"
#include "EStationStopState.generated.h"

UENUM()
enum class EStationStopState : uint8 {
    EInert,
    EStopUncalled,
    EStopAll,
};

