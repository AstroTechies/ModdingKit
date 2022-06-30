#pragma once
#include "CoreMinimal.h"
#include "ItemConversionFormula.h"
#include "ItemCraftingFormula.generated.h"

UCLASS(Blueprintable, NonTransient)
class ASTRO_API UItemCraftingFormula : public UItemConversionFormula
{
    GENERATED_BODY()
public:
    UItemCraftingFormula();
};
