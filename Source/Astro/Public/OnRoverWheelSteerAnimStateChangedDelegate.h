#pragma once
#include "CoreMinimal.h"
#include "OnRoverWheelSteerAnimStateChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoverWheelSteerAnimStateChanged, bool, bWheelsAreTurning);

