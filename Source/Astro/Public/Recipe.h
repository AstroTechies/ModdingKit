#pragma once
#include "CoreMinimal.h"
#include "ItemRecipeIngredient.h"
#include "Recipe.generated.h"

USTRUCT(BlueprintType)
struct FRecipe {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemRecipeIngredient> Ingredients;
    
    ASTRO_API FRecipe();
};

