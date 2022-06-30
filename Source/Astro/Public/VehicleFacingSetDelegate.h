#pragma once
#include "CoreMinimal.h"
#include "VehicleFacingSetDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVehicleFacingSet, bool, facingBackward);

