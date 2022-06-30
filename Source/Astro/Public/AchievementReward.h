#pragma once
#include "CoreMinimal.h"
#include "AchievementReward.generated.h"

USTRUCT()
struct FAchievementReward {
    GENERATED_BODY()
public:
    UPROPERTY()
    FString ItemId;
    
    UPROPERTY()
    FString Item;
    
    ASTRO_API FAchievementReward();
};

