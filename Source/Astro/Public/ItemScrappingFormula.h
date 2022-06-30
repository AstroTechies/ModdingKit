#pragma once
#include "CoreMinimal.h"
#include "ItemConversionFormula.h"
#include "ItemScrappingFormula.generated.h"

UCLASS(Blueprintable, NonTransient)
class ASTRO_API UItemScrappingFormula : public UItemConversionFormula
{
    GENERATED_BODY()
public:
    UItemScrappingFormula();
};
