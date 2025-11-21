#pragma once
#include "CoreMinimal.h"
#include "EAstroGameMenuTutorialSlideDeckKey.generated.h"

UENUM(BlueprintType)
enum class EAstroGameMenuTutorialSlideDeckKey : uint8 {
    Invalid,
    Power,
    SoilExcavation,
    Research,
    Printers,
    BaseBuilding,
    CreativeMode,
    QHAll,
    QHPlanets,
    QHResources,
    Automation,
    Missions,
    AdventurePopup,
    Flora,
    Rails,
    Expansion,
    GW_QHResources,
    GW_Tutorial,
    MegaTech_Upsell,
    MegaTech_Tutorial,
};

