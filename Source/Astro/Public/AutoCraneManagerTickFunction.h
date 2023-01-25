#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TickFunction -FallbackName=TickFunction
#include "AutoCraneManagerTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FAutoCraneManagerTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    ASTRO_API FAutoCraneManagerTickFunction();
};

template<>
struct TStructOpsTypeTraits<FAutoCraneManagerTickFunction> : public TStructOpsTypeTraitsBase2<FAutoCraneManagerTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

