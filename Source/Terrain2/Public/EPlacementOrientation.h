#pragma once
#include "CoreMinimal.h"
#include "EPlacementOrientation.generated.h"

UENUM()
enum class EPlacementOrientation : uint8 {
    AlignToSurfaceNormal,
    AlignToSurfaceNormalInverted,
    AlignToPlanetUp,
    AlignToPlanetUpInverted,
};

