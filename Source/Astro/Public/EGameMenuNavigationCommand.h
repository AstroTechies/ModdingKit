#pragma once
#include "CoreMinimal.h"
#include "EGameMenuNavigationCommand.generated.h"

UENUM(BlueprintType)
enum class EGameMenuNavigationCommand : uint8 {
    None,
    Left,
    Right,
    Up,
    Down,
    TabRight,
    TabLeft,
    LeftOrTabLeft,
    RightOrTabRight,
    Back,
    Exit,
    UseOrEdit,
    ScrollDown,
    ScrollUp,
    ScrollPageDown,
    ScrollPageUp,
    ChangeUsers,
    ToggleDebugMenu,
    ToggleMOTD,
    ToggleAstropedia,
    ToggleStore,
    OpenUpsell,
    OpenStarSeekerUpsell,
    OpenMegaTechUpsell,
    Null,
};

