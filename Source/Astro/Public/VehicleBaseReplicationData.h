#pragma once
#include "CoreMinimal.h"
#include "VehicleBaseReplicationData.generated.h"

class AAstroPlayerController;
class ASeatBase;

USTRUCT(BlueprintType)
struct FVehicleBaseReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY()
    AAstroPlayerController* DrivingController;
    
    UPROPERTY()
    ASeatBase* SeatPilotingThisVehicle;
    
    ASTRO_API FVehicleBaseReplicationData();
};

