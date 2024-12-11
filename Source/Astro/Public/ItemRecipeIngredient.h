#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ItemRecipeIngredient.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FItemRecipeIngredient {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Count;
    
    ASTRO_API FItemRecipeIngredient();
};

