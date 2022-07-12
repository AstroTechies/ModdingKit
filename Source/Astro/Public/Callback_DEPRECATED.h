#pragma once
#include "CoreMinimal.h"
#include "Callback_DEPRECATED.generated.h"

class UObject;
class UFunction;

USTRUCT(BlueprintType)
struct FCallback_DEPRECATED {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* Object;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFunction* Function;
    
    UPROPERTY(EditAnywhere)
    uint32 ObjectIndex;
    
    ASTRO_API FCallback_DEPRECATED();
};

