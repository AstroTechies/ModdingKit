#pragma once
#include "CoreMinimal.h"
#include "OnTunnelBoringDrillActivatedDelegate.generated.h"

class AVehicleDrill;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTunnelBoringDrillActivated, AVehicleDrill*, VehicleDrill);

