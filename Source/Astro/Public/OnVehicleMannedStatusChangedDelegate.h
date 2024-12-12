#pragma once
#include "CoreMinimal.h"
#include "OnVehicleMannedStatusChangedDelegate.generated.h"

class AAstroPlayerController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVehicleMannedStatusChanged, AAstroPlayerController*, VehicleDriver);

