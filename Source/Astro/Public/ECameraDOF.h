#pragma once
#include "CoreMinimal.h"
#include "ECameraDOF.generated.h"

UENUM()
enum class ECameraDOF : uint8 {
    Pitch,
    Yaw,
    Roll,
    VerticalOffset,
    HorizontalOffset,
    Distance,
    FieldOfView,
    WorldTransform,
};

