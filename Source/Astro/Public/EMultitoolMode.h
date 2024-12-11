#pragma once
#include "CoreMinimal.h"
#include "EMultitoolMode.generated.h"

UENUM(BlueprintType)
enum class EMultitoolMode : uint8 {
    Multitool,
    SlotSelection,
    Terrain,
    None,
};

