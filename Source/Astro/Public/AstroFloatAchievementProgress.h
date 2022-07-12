#pragma once
#include "CoreMinimal.h"
#include "EAstroAchievementKeys.h"
#include "AstroFloatAchievementProgress.generated.h"

USTRUCT(BlueprintType)
struct FAstroFloatAchievementProgress {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroAchievementKeys Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Progress;
    
    ASTRO_API FAstroFloatAchievementProgress();
};

