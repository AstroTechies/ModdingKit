#pragma once
#include "CoreMinimal.h"
#include "LockingMechanismSignalDelegate.h"
#include "LockingMechanism.h"
#include "PowerFlowLockingMechanism.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UPowerFlowLockingMechanism : public ULockingMechanism {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLockingMechanismSignal OnAccumulatedFullyPoweredTimeChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float AccumulatedFullyPoweredTime;
    
public:
    UPowerFlowLockingMechanism();
    UFUNCTION()
    void OnFullyPowered();
    
    UFUNCTION()
    void OnEndFullyPowered();
    
};

