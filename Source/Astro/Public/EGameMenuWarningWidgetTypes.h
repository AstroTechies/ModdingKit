#pragma once
#include "CoreMinimal.h"
#include "EGameMenuWarningWidgetTypes.generated.h"

UENUM(BlueprintType)
enum class EGameMenuWarningWidgetTypes : uint8 {
    None,
    AchievementProgressionWarning,
    CustomGamePerformanceWarning,
    CustomGamePlayfabWarning,
    CustomGameSwitchModifiersWarning,
    ExperimentalSettingsWarning,
    InsufficientSpaceForSaveWarning,
    CustomGamePostGameKickedNotice,
    Count,
};

