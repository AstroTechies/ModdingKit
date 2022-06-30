#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "PerformAuxActionSignalDelegate.generated.h"

class AAstroPlayerController;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPerformAuxActionSignal, AAstroPlayerController*, OriginatingController, EInputEvent, eventType);

