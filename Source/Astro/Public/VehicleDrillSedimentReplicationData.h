#pragma once
#include "CoreMinimal.h"
#include "VehicleDrillSedimentReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FVehicleDrillSedimentReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY()
    int32 AvailableSediment;
    
    UPROPERTY()
    int32 SedimentCapacity;
    
    ASTRO_API FVehicleDrillSedimentReplicationData();
};

