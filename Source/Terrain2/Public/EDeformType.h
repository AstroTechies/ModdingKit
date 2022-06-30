#pragma once
#include "CoreMinimal.h"
#include "EDeformType.generated.h"

UENUM(BlueprintType)
enum class EDeformType : uint8 {
    Subtract,
    Add,
    Flatten,
    ColorPick,
    ColorPaint,
    CountCreative,
    Crater,
    FlattenSubtractOnly,
    FlattenAddOnly,
    TrueFlatStamp,
    PlatformSurface,
    Count,
};

