#pragma once
#include "CoreMinimal.h"
#include "VehicleBaseReplicationData.generated.h"

class AAstroPlayerController;
class ASeatBase;

USTRUCT(BlueprintType)
struct FVehicleBaseReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAstroPlayerController* DrivingController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASeatBase* SeatPilotingThisVehicle;
    
    ASTRO_API FVehicleBaseReplicationData();
};

