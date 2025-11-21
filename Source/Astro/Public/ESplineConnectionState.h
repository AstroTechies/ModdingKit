#pragma once
#include "CoreMinimal.h"
#include "ESplineConnectionState.generated.h"

UENUM(BlueprintType)
enum class ESplineConnectionState : uint8 {
    Asleep_Valid,
    Awake,
    GeneratingConnections,
    Asleep_Invalid,
};

