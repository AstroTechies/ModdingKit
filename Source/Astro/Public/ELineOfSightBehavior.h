#pragma once
#include "CoreMinimal.h"
#include "ELineOfSightBehavior.generated.h"

UENUM()
enum class ELineOfSightBehavior : uint8 {
    ERequireLineOfSight,
    EPreferLineOfSight,
    EIgnoreLineOfSight,
};

