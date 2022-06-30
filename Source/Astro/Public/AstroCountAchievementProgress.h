#pragma once
#include "CoreMinimal.h"
#include "EAstroAchievementKeys.h"
#include "AstroCountAchievementProgress.generated.h"

USTRUCT(BlueprintType)
struct FAstroCountAchievementProgress {
    GENERATED_BODY()
public:
    UPROPERTY()
    EAstroAchievementKeys Key;
    
    UPROPERTY()
    int32 Progress;
    
    ASTRO_API FAstroCountAchievementProgress();
};

