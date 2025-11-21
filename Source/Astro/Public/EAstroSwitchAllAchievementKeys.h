#pragma once
#include "CoreMinimal.h"
#include "EAstroSwitchAllAchievementKeys.generated.h"

UENUM(BlueprintType)
enum class EAstroSwitchAllAchievementKeys : uint8 {
    SolveTerranEngine = 28,
    SolveBarrenEngine,
    SolveAridEngine,
    SolveExoticEngine,
    SolveExomoonEngine,
    SolveTundraEngine,
    SolveRadiatedEngine,
    BeatGame = 44,
    PlanetDance = 47,
    COUNT = 9,
    ZeroInvalid = 0,
};

