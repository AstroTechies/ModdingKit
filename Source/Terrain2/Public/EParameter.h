#pragma once
#include "CoreMinimal.h"
#include "EParameter.generated.h"

UENUM()
enum class EParameter {
    VoxelX,
    VoxelY,
    VoxelZ,
    VoxelNormalX,
    VoxelNormalY,
    VoxelNormalZ,
    InterVoxelWidth,
    PlanetRadius,
    LayerThickness,
    LayerFloor,
    Noise,
    Noise2,
    LogFile,
};

