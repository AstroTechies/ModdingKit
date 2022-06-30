#pragma once
#include "CoreMinimal.h"
#include "EStationMarkerType.generated.h"

UENUM(BlueprintType)
enum class EStationMarkerType : uint8 {
    Blue,
    Red,
    Orange,
    Yellow,
    Green,
    Purple,
    Black,
    White,
    None,
};

