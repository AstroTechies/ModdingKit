#pragma once
#include "CoreMinimal.h"
#include "CameraContextSignalDelegate.generated.h"

class UCameraContext;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCameraContextSignal, UCameraContext*, CameraContext);

