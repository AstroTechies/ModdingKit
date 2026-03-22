#pragma once
#include "CoreMinimal.h"
#include "AstroAchievementProgressReport.h"
#include "AstroPlayerAchievementProgress.h"
#include "AchievementProgressReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FAchievementProgressReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAstroAchievementProgressReport> AchievementProgressReportOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroPlayerAchievementProgress AchievementProgress;
    
    ASTRO_API FAchievementProgressReplicationData();
};

