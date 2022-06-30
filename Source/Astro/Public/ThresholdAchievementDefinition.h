#pragma once
#include "CoreMinimal.h"
#include "EAstroAchievementKeys.h"
#include "ThresholdAchievementDefinition.generated.h"

USTRUCT(BlueprintType)
struct FThresholdAchievementDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    EAstroAchievementKeys AchievementKey;
    
    UPROPERTY(EditDefaultsOnly)
    bool bUseNamedThresholds;
    
    UPROPERTY(EditDefaultsOnly)
    float Threshold;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<FName, float> NamedThresholds;
    
    ASTRO_API FThresholdAchievementDefinition();
};

