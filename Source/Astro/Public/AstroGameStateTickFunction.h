#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TickFunction -FallbackName=TickFunction
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

