#pragma once
#include "CoreMinimal.h"
#include "ETerrainPlacementMode.generated.h"

UENUM()
enum class ETerrainPlacementMode : uint8 {
    Stick,
    Bury,
    Free,
    None,
};

