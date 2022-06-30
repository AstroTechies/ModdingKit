#pragma once
#include "CoreMinimal.h"
#include "EVehicleDrillToolMode.h"
#include "VehicleDrillReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FVehicleDrillReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY()
    bool ToolIsActive;
    
    UPROPERTY()
    bool CollectedExcessTerrain;
    
    UPROPERTY()
    EVehicleDrillToolMode DrillToolMode;
    
    ASTRO_API FVehicleDrillReplicationData();
};

