#pragma once
#include "CoreMinimal.h"
#include "ECraftingOrgin.generated.h"

UENUM(BlueprintType)
enum class ECraftingOrgin : uint8 {
    None,
    Crafted,
    MinedAnywhere,
    OreMinedAnywhere,
    MinedOnPlanet,
    OreMinedOnPlanet,
    Tapped,
    Smelted,
    Extracted,
    Condensed,
    Catalyzed,
    BackpackPrinted,
    Printed,
    Discovered,
};

