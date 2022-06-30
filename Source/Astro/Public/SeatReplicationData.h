#pragma once
#include "CoreMinimal.h"
#include "SeatReplicationData.generated.h"

class AVehicleBase;

USTRUCT(BlueprintType)
struct FSeatReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY()
    AVehicleBase* VehicleSlottedTo;
    
    ASTRO_API FSeatReplicationData();
};

