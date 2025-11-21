#pragma once
#include "CoreMinimal.h"
#include "EGameControllerType.generated.h"

UENUM(BlueprintType)
enum class EGameControllerType : uint8 {
    Xbox,
    PS4,
    PS5,
    Switch,
    Undefined,
};

