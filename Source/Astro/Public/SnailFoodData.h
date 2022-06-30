#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SnailFoodData.generated.h"

class UItemList;

USTRUCT(BlueprintType)
struct FSnailFoodData {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float FedDurationScalar;
    
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UItemList> FoodItems;
    
    ASTRO_API FSnailFoodData();
};

