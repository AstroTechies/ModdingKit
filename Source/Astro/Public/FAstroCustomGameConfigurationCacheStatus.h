#pragma once
#include "CoreMinimal.h"
#include "FAstroCustomGameConfigurationCacheStatus.generated.h"

UENUM(BlueprintType)
enum class FAstroCustomGameConfigurationCacheStatus : uint8 {
    Dirty,
    Updating,
    Ready,
    Count,
};

