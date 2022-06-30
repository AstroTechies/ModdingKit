#pragma once
#include "CoreMinimal.h"
#include "SignalActivationBinding.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FSignalActivationBinding {
    GENERATED_BODY()
public:
    UPROPERTY()
    UObject* Owner;
    
    UPROPERTY()
    int32 ActivatedOffset;
    
    UPROPERTY()
    int32 DeactivatedOffset;
    
    ASTRO_API FSignalActivationBinding();
};

