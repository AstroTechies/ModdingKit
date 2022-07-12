#pragma once
#include "CoreMinimal.h"
#include "ItemConversionRecipe.h"
#include "AstroDatumRef.h"
#include "PossibleItemConversion.generated.h"

USTRUCT(BlueprintType)
struct FPossibleItemConversion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemConversionRecipe ConversionRecipe;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAstroDatumRef> InputItemEntityRefs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseLiteralItemTypeForInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OutputItemIndex;
    
    ASTRO_API FPossibleItemConversion();
};

