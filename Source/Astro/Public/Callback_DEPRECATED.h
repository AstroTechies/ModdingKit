#pragma once
#include "CoreMinimal.h"
#include "Callback_DEPRECATED.generated.h"

class UObject;
class UFunction;

USTRUCT(BlueprintType)
struct FCallback_DEPRECATED {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    UObject* Object;
    
    UPROPERTY(Transient)
    UFunction* Function;
    
    UPROPERTY()
    uint32 ObjectIndex;
    
    ASTRO_API FCallback_DEPRECATED();
};

