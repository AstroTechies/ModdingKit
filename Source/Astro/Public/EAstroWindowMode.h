#pragma once
#include "CoreMinimal.h"
#include "EAstroWindowMode.generated.h"

UENUM(BlueprintType)
enum class EAstroWindowMode : uint8 {
    Fullscreen,
    WindowedFullscreen,
    Windowed,
    NumWindowModes,
};

