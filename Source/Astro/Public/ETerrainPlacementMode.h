#pragma once
#include "CoreMinimal.h"
#include "ETerrainPlacementMode.generated.h"

UENUM(BlueprintType)
enum class ETerrainPlacementMode : uint8 {
    Stick,
    Bury,
    Free,
    None,
};

