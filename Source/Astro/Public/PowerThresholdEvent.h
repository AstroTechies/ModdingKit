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
    
    UPROPERTY(BlueprintAssignable, EditAnywhere)
    FSignal OnBelowThreshold;
    
    UPROPERTY(BlueprintAssignable, EditAnywhere)
    FSignal OnAboveThreshold;
    
    ASTRO_API FPowerThresholdEvent();
};

