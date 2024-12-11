#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "RewardResult.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FRewardResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> RewardType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsDurableUnlock: 1;
    
    ASTRO_API FRewardResult();
};

