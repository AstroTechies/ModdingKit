#pragma once
#include "CoreMinimal.h"
#include "EAirControlSecondaryType.generated.h"

UENUM(BlueprintType)
enum class EAirControlSecondaryType : uint8 {
    Yaw,
    Roll,
    Blended,
};

