#pragma once
#include "CoreMinimal.h"
#include "EAchievementSaveDataType.h"
#include "EAstroAchievementKeys.h"
#include "ProgressionAchievementDefinition.generated.h"

USTRUCT()
struct FProgressionAchievementDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    EAstroAchievementKeys AchievementKey;
    
    UPROPERTY(EditDefaultsOnly)
    EAchievementSaveDataType SaveDataType;
    
    ASTRO_API FProgressionAchievementDefinition();
};

