#pragma once
#include "CoreMinimal.h"
#include "ETooltipArchetype.generated.h"

UENUM()
enum class ETooltipArchetype : uint8 {
    Custom,
    PhysicalItem,
    ItemIndicator,
    ClickableSlot,
    Salvage,
    PlanetProxy,
    CustomNonInputResponding,
    Salvage_Bundleable,
};

