#pragma once
#include "CoreMinimal.h"
#include "EPlacementImportanceMode.generated.h"

UENUM()
enum class EPlacementImportanceMode : uint8 {
    Lowest,
    Low,
    Normal,
    High,
    Highest,
};

