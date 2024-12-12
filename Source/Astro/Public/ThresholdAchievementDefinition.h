#pragma once
#include "CoreMinimal.h"
#include "EAstroAchievementKeys.h"
#include "ThresholdAchievementDefinition.generated.h"

USTRUCT(BlueprintType)
struct FThresholdAchievementDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroAchievementKeys AchievementKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseNamedThresholds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Threshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> NamedThresholds;
    
    ASTRO_API FThresholdAchievementDefinition();
};

