#pragma once
#include "CoreMinimal.h"
#include "AchievementReward.generated.h"

USTRUCT(BlueprintType)
struct FAchievementReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ItemId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Item;
    
    ASTRO_API FAchievementReward();
};

