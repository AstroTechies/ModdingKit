#pragma once
#include "CoreMinimal.h"
#include "ProgressionAchievementDefinition.h"
#include "CountAchievement.generated.h"

USTRUCT(BlueprintType)
struct FCountAchievement : public FProgressionAchievementDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NeededCount;
    
    ASTRO_API FCountAchievement();
};

