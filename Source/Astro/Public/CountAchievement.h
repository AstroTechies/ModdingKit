#pragma once
#include "CoreMinimal.h"
#include "ProgressionAchievementDefinition.h"
#include "CountAchievement.generated.h"

USTRUCT(BlueprintType)
struct FCountAchievement : public FProgressionAchievementDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    int32 NeededCount;
    
    ASTRO_API FCountAchievement();
};

