#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "ActiveItemConversionItemInput.h"
#include "ActiveItemConversionItemOutput.h"
#include "ActiveItemConversion.generated.h"

USTRUCT(BlueprintType)
struct FActiveItemConversion {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TArray<FAstroDatumRef> InputItemEntityRefs;
    
    UPROPERTY(SaveGame)
    TArray<FActiveItemConversionItemInput> ItemInputs;
    
    UPROPERTY(SaveGame)
    TArray<FActiveItemConversionItemOutput> ItemOutputs;
    
    UPROPERTY(SaveGame)
    float ProgressRatio;
    
    UPROPERTY(SaveGame)
    int32 ID;
    
    ASTRO_API FActiveItemConversion();
};

