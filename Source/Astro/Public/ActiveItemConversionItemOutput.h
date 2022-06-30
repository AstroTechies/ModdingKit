#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroDatumRef.h"
#include "ActiveItemConversionItemOutput.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FActiveItemConversionItemOutput {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TSubclassOf<UItemType> OutputItemType;
    
    UPROPERTY(SaveGame)
    int32 TargetOutputItemAmount;
    
    UPROPERTY(SaveGame)
    int32 OutputItemAmountProduced;
    
    UPROPERTY(SaveGame)
    FAstroDatumRef CurrentOutputItemEntityRef;
    
    ASTRO_API FActiveItemConversionItemOutput();
};

