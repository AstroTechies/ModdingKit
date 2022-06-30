#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "RewardSet.generated.h"

class UItemListWeighted;

USTRUCT(BlueprintType)
struct FRewardSet {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName SetName;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemListWeighted> Durables;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemListWeighted> Consumables;
    
    ASTRO_API FRewardSet();
};

