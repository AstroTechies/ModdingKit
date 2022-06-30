#pragma once
#include "CoreMinimal.h"
#include "EAstroAchievementKeys.h"
#include "AstroFloatAchievementProgress.generated.h"

USTRUCT(BlueprintType)
struct FAstroFloatAchievementProgress {
    GENERATED_BODY()
public:
    UPROPERTY()
    EAstroAchievementKeys Key;
    
    UPROPERTY()
    float Progress;
    
    ASTRO_API FAstroFloatAchievementProgress();
};

