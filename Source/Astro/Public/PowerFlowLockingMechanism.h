#pragma once
#include "CoreMinimal.h"
#include "LockingMechanism.h"
#include "LockingMechanismSignalDelegate.h"
#include "PowerFlowLockingMechanism.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UPowerFlowLockingMechanism : public ULockingMechanism
{
    GENERATED_BODY()
public:
    UPROPERTY()
    FLockingMechanismSignal OnAccumulatedFullyPoweredTimeChanged;

protected:
    UPROPERTY(SaveGame)
    float AccumulatedFullyPoweredTime;

public:
    UPowerFlowLockingMechanism();
    UFUNCTION()
    void OnFullyPowered();

    UFUNCTION()
    void OnEndFullyPowered();
};
