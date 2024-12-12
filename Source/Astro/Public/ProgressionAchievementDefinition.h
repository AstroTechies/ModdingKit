#pragma once
#include "CoreMinimal.h"
#include "EAchievementSaveDataType.h"
#include "EAstroAchievementKeys.h"
#include "ProgressionAchievementDefinition.generated.h"

USTRUCT(BlueprintType)
struct FProgressionAchievementDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroAchievementKeys AchievementKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAchievementSaveDataType SaveDataType;
    
    ASTRO_API FProgressionAchievementDefinition();
};

