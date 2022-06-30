#pragma once
#include "CoreMinimal.h"
#include "EFullnessActuatorEventType.generated.h"

UENUM(BlueprintType)
enum class EFullnessActuatorEventType : uint8 {
    None,
    Full,
    WasFull,
    Empty = 0x4,
    WasEmpty = 0x8,
    All = 0xF,
};

