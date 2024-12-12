#pragma once
#include "CoreMinimal.h"
#include "EAstroAchievementKeys.h"
#include "AstroCollectionAchievementProgress.generated.h"

USTRUCT(BlueprintType)
struct FAstroCollectionAchievementProgress {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroAchievementKeys Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CollectedItems;
    
    ASTRO_API FAstroCollectionAchievementProgress();
};

