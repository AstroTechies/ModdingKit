#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "ResourceExtractorManagerTickFunction.generated.h"

class UResourceExtractorManager;

USTRUCT(BlueprintType)
struct FResourceExtractorManagerTickFunction : public FTickFunction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceExtractorManager* Target;
    
    ASTRO_API FResourceExtractorManagerTickFunction();
};

template<>
struct TStructOpsTypeTraits<FResourceExtractorManagerTickFunction> : public TStructOpsTypeTraitsBase2<FResourceExtractorManagerTickFunction>
{
    enum
    {
        WithCopy = false
    };
};

