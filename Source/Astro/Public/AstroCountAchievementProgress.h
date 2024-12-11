#pragma once
#include "CoreMinimal.h"
#include "EAstroAchievementKeys.h"
#include "AstroCountAchievementProgress.generated.h"

USTRUCT(BlueprintType)
struct FAstroCountAchievementProgress {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroAchievementKeys Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Progress;
    
    ASTRO_API FAstroCountAchievementProgress();
};

