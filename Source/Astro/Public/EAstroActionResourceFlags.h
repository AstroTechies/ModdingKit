#pragma once
#include "CoreMinimal.h"
#include "EAstroActionResourceFlags.generated.h"

UENUM(BlueprintType)
enum class EAstroActionResourceFlags : uint8 {
    Montage,
    Movement,
    TakePicture,
};

