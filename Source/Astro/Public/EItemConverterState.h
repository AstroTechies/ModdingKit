#pragma once
#include "CoreMinimal.h"
#include "EItemConverterState.generated.h"

UENUM(BlueprintType)
enum class EItemConverterState : uint8 {
    Inactive,
    Active,
    Paused,
    Standby,
    Ready,
    Invalid,
};

