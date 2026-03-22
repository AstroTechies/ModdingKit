#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SnailFoodData.generated.h"

class UItemList;

USTRUCT(BlueprintType)
struct FSnailFoodData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FedDurationScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> FoodItems;
    
    ASTRO_API FSnailFoodData();
};

