#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
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

