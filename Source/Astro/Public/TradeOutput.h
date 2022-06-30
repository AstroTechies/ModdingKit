#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TradeOutput.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FTradeOutput {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UItemType>, float> OutputTypes;
    
    ASTRO_API FTradeOutput();
};

