#pragma once
#include "CoreMinimal.h"
#include "ProgressionAchievementDefinition.h"
#include "FloatCountAchievement.generated.h"

USTRUCT(BlueprintType)
struct FFloatCountAchievement : public FProgressionAchievementDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NeededCount;
    
    ASTRO_API FFloatCountAchievement();
};

