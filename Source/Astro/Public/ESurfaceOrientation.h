#pragma once
#include "CoreMinimal.h"
#include "ESurfaceOrientation.generated.h"

UENUM()
enum class ESurfaceOrientation : uint8 {
    TerrainNormal,
    TerrainNormalUphill,
    ComponentUp,
    PlanetUp,
    PlanetDown,
    Random,
};

