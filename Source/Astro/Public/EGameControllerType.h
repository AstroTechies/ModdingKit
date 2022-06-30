#pragma once
#include "CoreMinimal.h"
#include "EGameControllerType.generated.h"

UENUM()
enum class EGameControllerType : uint8 {
    Xbox,
    PS4,
    Switch,
    Undefined,
};

