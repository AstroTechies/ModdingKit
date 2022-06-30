#pragma once
#include "CoreMinimal.h"
#include "EAstroMissionObjectiveType.generated.h"

UENUM(BlueprintType)
enum class EAstroMissionObjectiveType : uint8 {
    HarvestResource,
    PrintItem,
    SlotItem,
    CreateItem,
    PowerItem,
    FullyChargeItem,
    FillItem,
    PlanetFall,
    FindGateChamber,
    ActivateGateChamber,
    FindGateEngine,
    ActivateGateEngine,
    Custom,
    ConnectToPower,
    SlottedByAutoArm,
    ItemPlaced,
    PuzzleSolved,
    CatalogUnlock,
    BytesReached,
    ResearchCompleted,
    ItemUsed,
    ItemExists,
    ConnectToOxygen,
    SlotInDeformTool,
    ExplodeItem,
    DrainItem,
    ConsumeItem,
    ItemPickedUp,
    ItemDoesntExist,
    None,
};

