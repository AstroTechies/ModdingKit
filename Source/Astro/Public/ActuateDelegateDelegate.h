#pragma once
#include "CoreMinimal.h"
#include "EFullnessActuatorEventType.h"
#include "ActuateDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActuateDelegate, EFullnessActuatorEventType, eventType);

