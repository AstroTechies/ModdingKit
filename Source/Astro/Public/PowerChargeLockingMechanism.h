#pragma once
#include "CoreMinimal.h"
#include "LockingMechanism.h"
#include "PowerChargeLockingMechanism.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UPowerChargeLockingMechanism : public ULockingMechanism {
    GENERATED_BODY()
public:
    UPowerChargeLockingMechanism();
    UFUNCTION(BlueprintCallable)
    void OnNotFullyCharged();
    
    UFUNCTION(BlueprintCallable)
    void OnFullyCharged();
    
};

