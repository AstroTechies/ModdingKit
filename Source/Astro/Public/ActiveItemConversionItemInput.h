#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroDatumRef.h"
#include "ActiveItemConversionItemInput.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FActiveItemConversionItemInput {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TSubclassOf<UItemType> InputItemType;
    
    UPROPERTY(SaveGame)
    FAstroDatumRef InputItemEntityRef;
    
    UPROPERTY(SaveGame)
    int32 StartingInputItemAmount;
    
    UPROPERTY(SaveGame)
    int32 TargetInputItemAmount;
    
    ASTRO_API FActiveItemConversionItemInput();
};

