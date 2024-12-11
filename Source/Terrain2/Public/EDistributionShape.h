#pragma once
#include "CoreMinimal.h"
#include "EDistributionShape.generated.h"

UENUM(BlueprintType)
enum class EDistributionShape : uint8 {
    Cone,
    Cylinder,
    Disc,
};

