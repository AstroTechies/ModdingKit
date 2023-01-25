#pragma once
#include "CoreMinimal.h"
#include "EAstroDiscreteInputOptionPlayerFacing.generated.h"

UENUM(BlueprintType)
enum class EAstroDiscreteInputOptionPlayerFacing : uint8 {
    Invalid,
    Forward,
    Backward,
    Left,
    Right,
    RoverForward,
    RoverReverse,
    Sprint,
    Jump,
    TerrainTool,
    Backpack,
    ContextLeft,
    ContextRight,
    TerrainAddModifier,
    TerrainFlattenModifier,
    Tether,
    Joy,
    Happy,
    Wave,
    What,
    Use,
    Catalog,
    ToggleCreativeDeformToolMenu,
    DeleteActiveMultiToolItem,
    DuplicateActiveMultiToolItem,
    ChangeDeformBrushSizeModifier,
    ChangeDeformBrushStrengthModifier,
    EmoteWheel,
    ActionWheel,
};

