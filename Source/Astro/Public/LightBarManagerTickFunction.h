#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "LightBarManagerTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FLightBarManagerTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    ASTRO_API FLightBarManagerTickFunction();
};

template<>
struct TStructOpsTypeTraits<FLightBarManagerTickFunction> : public TStructOpsTypeTraitsBase2<FLightBarManagerTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

