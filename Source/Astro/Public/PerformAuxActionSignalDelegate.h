#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EInputEvent -FallbackName=EInputEvent
#include "PerformAuxActionSignalDelegate.generated.h"

class AAstroPlayerController;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPerformAuxActionSignal, AAstroPlayerController*, OriginatingController, TEnumAsByte<EInputEvent>, eventType);

