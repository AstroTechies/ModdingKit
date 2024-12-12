#pragma once
#include "CoreMinimal.h"
#include "EPaintIndexType.generated.h"

UENUM(BlueprintType)
enum class EPaintIndexType : uint8 {
    SpencerPalette,
    PlanetPalette,
    SpecialPalette,
    Invalid,
};

