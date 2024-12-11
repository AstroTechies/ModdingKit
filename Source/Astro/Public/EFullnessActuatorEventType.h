#pragma once
#include "CoreMinimal.h"
#include "EFullnessActuatorEventType.generated.h"

UENUM(BlueprintType)
enum class EFullnessActuatorEventType : uint8 {
    None,
    Full,
    WasFull,
    Empty = 4,
    WasEmpty = 8,
    All = 15,
};

