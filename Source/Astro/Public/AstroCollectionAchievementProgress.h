#pragma once
#include "CoreMinimal.h"
#include "EAstroAchievementKeys.h"
#include "AstroCollectionAchievementProgress.generated.h"

USTRUCT(BlueprintType)
struct FAstroCollectionAchievementProgress {
    GENERATED_BODY()
public:
    UPROPERTY()
    EAstroAchievementKeys Key;
    
    UPROPERTY()
    TArray<FName> CollectedItems;
    
    ASTRO_API FAstroCollectionAchievementProgress();
};

