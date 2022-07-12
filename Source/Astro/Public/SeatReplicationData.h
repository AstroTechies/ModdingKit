#pragma once
#include "CoreMinimal.h"
#include "SeatReplicationData.generated.h"

class AVehicleBase;

USTRUCT(BlueprintType)
struct FSeatReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AVehicleBase* VehicleSlottedTo;
    
    ASTRO_API FSeatReplicationData();
};

