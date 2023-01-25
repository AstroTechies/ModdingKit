#pragma once
#include "CoreMinimal.h"
#include "EAugmentProperty.generated.h"

UENUM(BlueprintType)
enum class EAugmentProperty : uint8 {
    AP_BrushSize,
    AP_DeformationIntensity,
    AP_TerrainColor,
    AP_TerrainColor_R,
    AP_TerrainColor_G,
    AP_TerrainColor_B,
    AP_TerrainHardness,
    AP_TerrainSurfaceType,
    AP_PowerLevel,
    AP_Alignment,
    AP_HardnessTier,
    AP_MAX UMETA(Hidden),
};

