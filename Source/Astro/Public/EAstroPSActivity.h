#pragma once
#include "CoreMinimal.h"
#include "EAstroPSActivity.generated.h"

UENUM(BlueprintType)
enum class EAstroPSActivity : uint8 {
    None,
    Multiplayer,
    Awakening,
    BaseMissionChain,
    Glitchwalkers,
    JetPowerVehicles,
    Trains,
    Snails,
    Wanderer,
};

