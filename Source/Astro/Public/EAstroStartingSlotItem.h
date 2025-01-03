#pragma once
#include "CoreMinimal.h"
#include "EAstroStartingSlotItem.generated.h"

UENUM(BlueprintType)
enum class EAstroStartingSlotItem : uint8 {
    None,
    SmallPrinter,
    Packager,
    LevelingBlock,
    Tethers,
    OxygenFilters,
    OxygenTank,
    PortableOxygenator,
    SmallCanister,
    Beacon,
    Worklight,
    Glowsticks,
    Floodlight,
    SmallGenerator,
    PowerCells,
    SmallSolarPanel,
    SmallWindTurbine,
    SmallBattery,
    BoostMod,
    WideMod,
    NarrowMod,
    InhibitorMod,
    AlignmentMod,
    DrillMod_Tier1,
    DrillMod_Tier2,
    DrillMod_Tier3,
    Dynamite,
    SmallCamera,
    SmallTrumpetHorn,
    SmallSqueakerHorn,
    TerrainAnalyzer,
    SolidFuelJumpJet,
    HydrazineJetPack,
    Hoverboard,
    QT_RTG,
    Hydrazine,
    NumTypes,
    Count,
};

