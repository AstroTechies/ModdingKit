#pragma once
#include "CoreMinimal.h"
#include "ETeleportationDestinationType.generated.h"

UENUM()
enum class ETeleportationDestinationType : uint8 {
    ExactLocation,
    GateObject,
};

