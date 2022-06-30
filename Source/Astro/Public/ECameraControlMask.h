#pragma once
#include "CoreMinimal.h"
#include "ECameraControlMask.generated.h"

UENUM()
enum class ECameraControlMask : uint8 {
    All,
    MouseOnly,
    GamepadOnly,
};

