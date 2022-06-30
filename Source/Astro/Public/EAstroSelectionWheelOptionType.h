#pragma once
#include "CoreMinimal.h"
#include "EAstroSelectionWheelOptionType.generated.h"

UENUM(BlueprintType)
enum class EAstroSelectionWheelOptionType : uint8 {
    Emote,
    OpenCatalog,
    OpenMissionLog,
    OpenCompass,
    OpenTerrianToolMenu,
    OpenDrone,
    None,
};

