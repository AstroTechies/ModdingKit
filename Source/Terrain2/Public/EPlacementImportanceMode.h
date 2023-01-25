#pragma once
#include "CoreMinimal.h"
#include "EPlacementImportanceMode.generated.h"

UENUM(BlueprintType)
enum class EPlacementImportanceMode : uint8 {
    Lowest,
    Low,
    Normal,
    High,
    Highest,
};

