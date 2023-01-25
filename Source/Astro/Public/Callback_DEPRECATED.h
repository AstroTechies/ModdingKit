#pragma once
#include "CoreMinimal.h"
#include "Callback_DEPRECATED.generated.h"

class UFunction;
class UObject;

USTRUCT(BlueprintType)
struct FCallback_DEPRECATED {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* Object;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFunction* Function;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ObjectIndex;
    
    ASTRO_API FCallback_DEPRECATED();
};

