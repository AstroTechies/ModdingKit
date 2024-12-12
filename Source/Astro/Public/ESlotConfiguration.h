#pragma once
#include "CoreMinimal.h"
#include "ESlotConfiguration.generated.h"

UENUM(BlueprintType)
enum class ESlotConfiguration : uint8 {
    Vertical,
    VerticalLeft,
    Horizontal,
    CameraFacingLeft,
    CameraFacingRight,
    HorizontalAux,
    VerticalAux,
};

