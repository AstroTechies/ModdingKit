#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
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

