#pragma once
#include "CoreMinimal.h"
#include "EGamePlatform.generated.h"

UENUM()
enum class EGamePlatform : uint8 {
    PC,
    UniversalWindows,
    XboxOne,
    PS4,
    Linux,
    Switch,
};

