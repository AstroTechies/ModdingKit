#pragma once
#include "CoreMinimal.h"
#include "EScannerTargetDistance.h"
#include "ScannerTargetDistanceSignalDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FScannerTargetDistanceSignal, EScannerTargetDistance, newDistance);

