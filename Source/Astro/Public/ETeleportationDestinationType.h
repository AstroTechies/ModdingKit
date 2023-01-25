#pragma once
#include "CoreMinimal.h"
#include "ETeleportationDestinationType.generated.h"

UENUM(BlueprintType)
enum class ETeleportationDestinationType : uint8 {
    ExactLocation,
    GateObject,
};

