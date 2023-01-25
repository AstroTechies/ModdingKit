#pragma once
#include "CoreMinimal.h"
#include "EAstroSwitchAllAchievementKeys.generated.h"

UENUM(BlueprintType)
enum class EAstroSwitchAllAchievementKeys : uint8 {
    SolveTerranEngine = 0x1C,
    SolveBarrenEngine,
    SolveAridEngine,
    SolveExoticEngine,
    SolveExomoonEngine,
    SolveTundraEngine,
    SolveRadiatedEngine,
    BeatGame = 0x2C,
    PlanetDance = 0x2F,
    COUNT = 0x9,
    EAstroSwitchAllAchievementKeys_MAX = 0x30,
};

