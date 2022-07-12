#pragma once
#include "CoreMinimal.h"
#include "SignalActivationBinding.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FSignalActivationBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActivatedOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DeactivatedOffset;
    
    ASTRO_API FSignalActivationBinding();
};

