#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemConversionFormula.generated.h"

UCLASS(Blueprintable, Abstract, Transient)
class ASTRO_API UItemConversionFormula : public UObject
{
    GENERATED_BODY()
public:
    UItemConversionFormula();
};
