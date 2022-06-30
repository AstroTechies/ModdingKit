#pragma once
#include "CoreMinimal.h"
#include "ItemConversionRecipe.h"
#include "AstroDatumRef.h"
#include "PossibleItemConversion.generated.h"

USTRUCT()
struct FPossibleItemConversion {
    GENERATED_BODY()
public:
    UPROPERTY()
    FItemConversionRecipe ConversionRecipe;
    
    UPROPERTY()
    TArray<FAstroDatumRef> InputItemEntityRefs;
    
    UPROPERTY()
    bool UseLiteralItemTypeForInput;
    
    UPROPERTY()
    int32 OutputItemIndex;
    
    ASTRO_API FPossibleItemConversion();
};

