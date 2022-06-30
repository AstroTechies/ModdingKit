#pragma once
#include "CoreMinimal.h"
#include "LockingMechanism.h"
#include "PowerChargeLockingMechanism.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UPowerChargeLockingMechanism : public ULockingMechanism
{
    GENERATED_BODY()
public:
    UPowerChargeLockingMechanism();
    UFUNCTION()
    void OnNotFullyCharged();

    UFUNCTION()
    void OnFullyCharged();
};
