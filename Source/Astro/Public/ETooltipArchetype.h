#pragma once
#include "CoreMinimal.h"
#include "ETooltipArchetype.generated.h"

UENUM(BlueprintType)
enum class ETooltipArchetype : uint8 {
    Custom,
    PhysicalItem,
    ItemIndicator,
    ClickableSlot,
    Salvage,
    PlanetProxy,
    CustomNonInputResponding,
    Salvage_Bundleable,
    Salvage_Small,
};

