#pragma once
#include "CoreMinimal.h"
#include "ESurfaceCriteriaNormalMode.generated.h"

UENUM()
enum class ESurfaceCriteriaNormalMode : uint8 {
    Any,
    FlatterThan,
    SteeperThan,
};

