#pragma once
#include "CoreMinimal.h"
#include "ReplicatedPowerState.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedPowerState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Flags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 CurrentCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StorageCapacity;
    
    ASTRO_API FReplicatedPowerState();
};

