#pragma once
#include "CoreMinimal.h"
#include "ETooltipArchetype.generated.h"

UENUM(BlueprintType)
enum class ETooltipArchetype : uint8 {
    Custom,
    PhysicalItem,
    PhysicalItemWithPower,
    ItemIndicator,
    ClickableSlot,
    Salvage,
    PlanetProxy,
    CustomNonInputResponding,
    Salvage_Bundleable,
    Salvage_Small,
};

