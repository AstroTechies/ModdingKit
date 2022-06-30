#pragma once
#include "CoreMinimal.h"
#include "EGravityType.generated.h"

UENUM(BlueprintType)
enum class EGravityType : uint8 {
    Spherical,
    Cylindrical,
    Constant,
};

