#pragma once
#include "CoreMinimal.h"
#include "ItemConversionFormula.h"
#include "SoilCentrifugeFormula.generated.h"

UCLASS(Blueprintable, NonTransient)
class ASTRO_API USoilCentrifugeFormula : public UItemConversionFormula
{
    GENERATED_BODY()
public:
    USoilCentrifugeFormula();
};
