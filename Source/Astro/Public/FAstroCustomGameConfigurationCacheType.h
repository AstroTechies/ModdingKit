#pragma once
#include "CoreMinimal.h"
#include "FAstroCustomGameConfigurationCacheType.generated.h"

UENUM(BlueprintType)
enum class FAstroCustomGameConfigurationCacheType : uint8 {
    LocalDisk,
    LocalCloud,
    Combined,
    Count,
};

