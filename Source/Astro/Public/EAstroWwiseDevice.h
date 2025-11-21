#pragma once
#include "CoreMinimal.h"
#include "EAstroWwiseDevice.generated.h"

UENUM(BlueprintType)
enum class EAstroWwiseDevice : uint8 {
    None,
    Controller_Speaker,
    Controller_Vibration,
};

