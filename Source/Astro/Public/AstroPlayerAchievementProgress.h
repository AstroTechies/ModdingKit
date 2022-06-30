#pragma once
#include "CoreMinimal.h"
#include "AstroCollectionAchievementProgress.h"
#include "AstroCountAchievementProgress.h"
#include "AstroFloatAchievementProgress.h"
#include "AstroPlayerAchievementProgress.generated.h"

USTRUCT()
struct FAstroPlayerAchievementProgress {
    GENERATED_BODY()
public:
    UPROPERTY()
    TArray<FAstroCountAchievementProgress> CountProgress;
    
    UPROPERTY()
    TArray<FAstroFloatAchievementProgress> FloatProgress;
    
    UPROPERTY(SaveGame)
    TArray<FAstroCollectionAchievementProgress> CollectionProgress;
    
    ASTRO_API FAstroPlayerAchievementProgress();
};

