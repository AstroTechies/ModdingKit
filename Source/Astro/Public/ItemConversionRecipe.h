#pragma once
#include "CoreMinimal.h"
#include "ItemQuantityPair.h"
#include "ItemRecipeIngredient.h"
#include "ItemConversionRecipe.generated.h"

USTRUCT(BlueprintType)
struct FItemConversionRecipe {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemRecipeIngredient> Ingredients;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemQuantityPair> OutputItems;
    
    ASTRO_API FItemConversionRecipe();
};

