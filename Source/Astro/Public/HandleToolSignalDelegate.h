#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "ClickResult.h"
#include "HandleToolSignalDelegate.generated.h"

class APlayController;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FHandleToolSignal, APlayController*, Controller, const FHitResult&, toolHit, const FClickResult&, ClickResult, bool, startedInteraction, bool, usingTool, bool, justActivated, bool, canUse);

