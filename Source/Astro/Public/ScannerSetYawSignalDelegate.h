#pragma once
#include "CoreMinimal.h"
#include "ScannerSetYawSignalDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FScannerSetYawSignal, float, Yaw);

