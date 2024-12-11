#pragma once
#include "CoreMinimal.h"
#include "ERaycastDistributionShape.generated.h"

UENUM(BlueprintType)
enum class ERaycastDistributionShape : uint8 {
    Cone,
    Cylinder,
    Disc,
};

