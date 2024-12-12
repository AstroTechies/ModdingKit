#pragma once
#include "CoreMinimal.h"
#include "ELineOfSightBehavior.generated.h"

UENUM(BlueprintType)
enum class ELineOfSightBehavior : uint8 {
    ERequireLineOfSight,
    EPreferLineOfSight,
    EIgnoreLineOfSight,
};

