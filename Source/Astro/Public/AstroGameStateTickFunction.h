#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "AstroGameStateTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FAstroGameStateTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    ASTRO_API FAstroGameStateTickFunction();
};

template<>
struct TStructOpsTypeTraits<FAstroGameStateTickFunction> : public TStructOpsTypeTraitsBase2<FAstroGameStateTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

