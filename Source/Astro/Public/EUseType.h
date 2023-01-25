#pragma once
#include "CoreMinimal.h"
#include "EUseType.generated.h"

UENUM(BlueprintType)
enum class EUseType : uint8 {
    None,
    Tooltip,
    Aux,
    Actuator = 0x4,
    All = 0x7,
};

