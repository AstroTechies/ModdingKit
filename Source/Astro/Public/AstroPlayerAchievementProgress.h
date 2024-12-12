#pragma once
#include "CoreMinimal.h"
#include "AstroCollectionAchievementProgress.h"
#include "AstroCountAchievementProgress.h"
#include "AstroFloatAchievementProgress.h"
#include "AstroPlayerAchievementProgress.generated.h"

USTRUCT(BlueprintType)
struct FAstroPlayerAchievementProgress {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAstroCountAchievementProgress> CountProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAstroFloatAchievementProgress> FloatProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAstroCollectionAchievementProgress> CollectionProgress;
    
    ASTRO_API FAstroPlayerAchievementProgress();
};

