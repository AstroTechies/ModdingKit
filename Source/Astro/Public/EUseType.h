#pragma once
#include "CoreMinimal.h"
#include "EUseType.generated.h"

UENUM(BlueprintType)
enum class EUseType : uint8 {
    None,
    Tooltip,
    Aux,
    Actuator = 4,
    All = 7,
};

