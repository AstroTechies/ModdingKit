#pragma once
#include "CoreMinimal.h"
#include "RewardPossibility.generated.h"

USTRUCT(BlueprintType)
struct FRewardPossibility {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DurableSetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FallbackConsumableSetName;
    
    ASTRO_API FRewardPossibility();
};

