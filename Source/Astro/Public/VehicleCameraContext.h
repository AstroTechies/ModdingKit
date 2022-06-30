#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "VehicleCameraContext.generated.h"

UCLASS(Blueprintable, Blueprintable)
class UVehicleCameraContext : public UCameraContext
{
    GENERATED_BODY()
public:
    UVehicleCameraContext();
};
