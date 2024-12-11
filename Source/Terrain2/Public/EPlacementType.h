#pragma once
#include "CoreMinimal.h"
#include "EPlacementType.generated.h"

UENUM(BlueprintType)
enum class EPlacementType : uint8 {
    Ground,
    Ceiling,
    Wall,
    Buried,
    None,
};

