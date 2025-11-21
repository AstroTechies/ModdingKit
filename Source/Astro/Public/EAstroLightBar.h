#pragma once
#include "CoreMinimal.h"
#include "EAstroLightBar.generated.h"

UENUM(BlueprintType)
enum class EAstroLightBar : uint8 {
    None,
    Oxygen_Tethered,
    Oxygen_Suffocating,
    SpaceVehicles_Traveling,
    LandVehicles_Traveling,
    Snail_NoFood,
};

