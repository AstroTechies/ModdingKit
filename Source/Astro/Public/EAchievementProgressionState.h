#pragma once
#include "CoreMinimal.h"
#include "EAchievementProgressionState.generated.h"

UENUM(BlueprintType)
enum class EAchievementProgressionState : uint8 {
    Unknown,
    Enabled,
    DisabledCreativeMode,
    DisabledIndividualDedicatedServer,
    DisabledBoth,
};

