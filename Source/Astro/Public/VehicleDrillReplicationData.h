#pragma once
#include "CoreMinimal.h"
#include "EVehicleDrillToolMode.h"
#include "VehicleDrillReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FVehicleDrillReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ToolIsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CollectedExcessTerrain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVehicleDrillToolMode DrillToolMode;
    
    ASTRO_API FVehicleDrillReplicationData();
};

