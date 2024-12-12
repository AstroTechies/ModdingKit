#pragma once
#include "CoreMinimal.h"
#include "AstroMovementMode.generated.h"

UENUM(BlueprintType)
enum class AstroMovementMode : uint8 {
    Walking,
    Falling,
    Sliding,
    Flying,
    CreativeFlight,
};

