#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TickFunction -FallbackName=TickFunction
#include "AstroFoliageDestructionManagerTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FAstroFoliageDestructionManagerTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    ASTRO_API FAstroFoliageDestructionManagerTickFunction();
};

template<>
struct TStructOpsTypeTraits<FAstroFoliageDestructionManagerTickFunction> : public TStructOpsTypeTraitsBase2<FAstroFoliageDestructionManagerTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

