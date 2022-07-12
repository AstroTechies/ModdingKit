#pragma once
#include "CoreMinimal.h"
#include "EStationLoadingState.generated.h"

UENUM()
enum class EStationLoadingState : uint8 {
    EInert,
    ELoad,
    EUnload,
};

