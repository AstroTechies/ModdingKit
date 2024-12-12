#pragma once
#include "CoreMinimal.h"
#include "EWorldOrientation.generated.h"

UENUM(BlueprintType)
enum class EWorldOrientation : uint8 {
    PlanetUp,
    PlanetDown,
    Random,
};

