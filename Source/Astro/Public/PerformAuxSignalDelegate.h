#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "PerformAuxSignalDelegate.generated.h"

class AAstroPlayerController;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPerformAuxSignal, AAstroPlayerController*, OriginatingController, EInputEvent, eventType);

