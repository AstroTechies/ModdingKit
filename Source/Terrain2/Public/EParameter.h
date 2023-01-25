#pragma once
#include "CoreMinimal.h"
#include "EParameter.generated.h"

UENUM(BlueprintType)
enum class EParameter : uint8 {
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

