#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TickFunction -FallbackName=TickFunction
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

