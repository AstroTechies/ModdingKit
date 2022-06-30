#pragma once
#include "CoreMinimal.h"
#include "EAstroAchievementKeys.h"
#include "AstroAchievementProgressReport.generated.h"

USTRUCT()
struct FAstroAchievementProgressReport {
    GENERATED_BODY()
public:
    UPROPERTY()
    EAstroAchievementKeys Key;
    
    UPROPERTY()
    float Progress;
    
    UPROPERTY()
    float NeededCount;
    
    ASTRO_API FAstroAchievementProgressReport();
};

