#pragma once
#include "CoreMinimal.h"
#include "VehicleDrillSedimentReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FVehicleDrillSedimentReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AvailableSediment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SedimentCapacity;
    
    ASTRO_API FVehicleDrillSedimentReplicationData();
};

