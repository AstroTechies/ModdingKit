#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "IndicatorsForTradeShipSlot.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FIndicatorsForTradeShipSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> IndicatorTypes;
    
    ASTRO_API FIndicatorsForTradeShipSlot();
};

