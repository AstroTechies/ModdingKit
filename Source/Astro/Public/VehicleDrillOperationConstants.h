#pragma once
#include "CoreMinimal.h"
#include "EDeformShape.h"
#include "EDeformType.h"
#include "VehicleDrillOperationConstants.generated.h"

USTRUCT(BlueprintType)
struct FVehicleDrillOperationConstants {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float Scale;
    
    UPROPERTY(EditDefaultsOnly)
    float Intensity;
    
    UPROPERTY(EditDefaultsOnly)
    EDeformType Operation;
    
    UPROPERTY(EditDefaultsOnly)
    EDeformShape Shape;
    
    UPROPERTY(EditDefaultsOnly)
    float PowerDraw;
    
    UPROPERTY(EditDefaultsOnly)
    float DummyScaleBonus;
    
    UPROPERTY(EditDefaultsOnly)
    float DummyIntensityBonus;
    
    UPROPERTY(EditDefaultsOnly)
    float DummyPowerDraw;
    
    ASTRO_API FVehicleDrillOperationConstants();
};

