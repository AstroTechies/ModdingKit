#pragma once
#include "CoreMinimal.h"
#include "ReplicatedPowerState.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedPowerState {
    GENERATED_BODY()
public:
    UPROPERTY()
    uint8 Flags;
    
    UPROPERTY()
    uint8 CurrentCharge;
    
    UPROPERTY()
    float StorageCapacity;
    
    ASTRO_API FReplicatedPowerState();
};

