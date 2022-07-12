#pragma once
#include "CoreMinimal.h"
#include "SignalDelegate.h"
#include "PowerThresholdEvent.generated.h"

USTRUCT(BlueprintType)
struct FPowerThresholdEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationThreshold;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnBelowThreshold;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnAboveThreshold;
    
    ASTRO_API FPowerThresholdEvent();
};

