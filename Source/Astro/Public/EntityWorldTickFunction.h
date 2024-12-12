#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "EntityWorldTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FEntityWorldTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    ASTRO_API FEntityWorldTickFunction();
};

template<>
struct TStructOpsTypeTraits<FEntityWorldTickFunction> : public TStructOpsTypeTraitsBase2<FEntityWorldTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

