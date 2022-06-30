#pragma once
#include "CoreMinimal.h"
#include "RewardPossibility.generated.h"

USTRUCT(BlueprintType)
struct FRewardPossibility {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float Probability;
    
    UPROPERTY(EditAnywhere)
    FName DurableSetName;
    
    UPROPERTY(EditAnywhere)
    FName FallbackConsumableSetName;
    
    ASTRO_API FRewardPossibility();
};

