#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "CollectibleTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FCollectibleTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    ASTRO_API FCollectibleTickFunction();
};

template<>
struct TStructOpsTypeTraits<FCollectibleTickFunction> : public TStructOpsTypeTraitsBase2<FCollectibleTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

