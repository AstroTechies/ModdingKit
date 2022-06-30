#pragma once
#include "CoreMinimal.h"
#include "AstroAchievementProgressReport.h"
#include "AstroPlayerAchievementProgress.h"
#include "AchievementProgressReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FAchievementProgressReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY()
    TArray<FAstroAchievementProgressReport> AchievementProgressReportOnly;
    
    UPROPERTY()
    FAstroPlayerAchievementProgress AchievementProgress;
    
    ASTRO_API FAchievementProgressReplicationData();
};

