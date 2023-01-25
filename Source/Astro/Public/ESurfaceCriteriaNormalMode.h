#pragma once
#include "CoreMinimal.h"
#include "ESurfaceCriteriaNormalMode.generated.h"

UENUM(BlueprintType)
enum class ESurfaceCriteriaNormalMode : uint8 {
    Any,
    FlatterThan,
    SteeperThan,
};

