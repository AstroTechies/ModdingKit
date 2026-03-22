#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "RewardSet.generated.h"

class UItemListWeighted;

USTRUCT(BlueprintType)
struct FRewardSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemListWeighted> Durables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemListWeighted> Consumables;
    
    ASTRO_API FRewardSet();
};

