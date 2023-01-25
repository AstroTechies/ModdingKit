#pragma once
#include "CoreMinimal.h"
#include "ECameraControlMask.generated.h"

UENUM(BlueprintType)
enum class ECameraControlMask : uint8 {
    All,
    MouseOnly,
    GamepadOnly,
};

