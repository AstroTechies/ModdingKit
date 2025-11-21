#pragma once
#include "CoreMinimal.h"
#include "EMegastructure.generated.h"

UENUM(BlueprintType)
enum class EMegastructure : uint8 {
    None,
    Wreck,
    LogisticsComplex,
    Biodome,
    Museum,
    OrbitalPlatform,
    Count,
};

