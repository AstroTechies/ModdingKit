#pragma once
#include "CoreMinimal.h"
#include "EAstroAchievementKeys.h"
#include "AstroAchievementProgressReport.generated.h"

USTRUCT(BlueprintType)
struct FAstroAchievementProgressReport {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroAchievementKeys Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Progress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NeededCount;
    
    ASTRO_API FAstroAchievementProgressReport();
};

