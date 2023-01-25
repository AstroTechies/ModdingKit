#pragma once
#include "CoreMinimal.h"
#include "ELevelingBlockVizSource.generated.h"

UENUM(BlueprintType)
enum class ELevelingBlockVizSource : uint8 {
    None,
    Placed,
    Hover,
};

