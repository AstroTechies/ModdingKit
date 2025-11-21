#pragma once
#include "CoreMinimal.h"
#include "EGamePlatform.generated.h"

UENUM(BlueprintType)
enum class EGamePlatform : uint8 {
    PC,
    UniversalWindows,
    XboxOne,
    PS4,
    PS5,
    Linux,
    Switch,
    WinGDK,
};

