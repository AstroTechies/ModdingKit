#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TickFunction -FallbackName=TickFunction
#include "CameraFacingManagerTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FCameraFacingManagerTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    ASTRO_API FCameraFacingManagerTickFunction();
};

template<>
struct TStructOpsTypeTraits<FCameraFacingManagerTickFunction> : public TStructOpsTypeTraitsBase2<FCameraFacingManagerTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

