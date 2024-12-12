#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ClickResult.h"
#include "HandleToolSignalDelegate.generated.h"

class APlayController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_EightParams(FHandleToolSignal, APlayController*, Controller, const FHitResult&, toolHit, const FClickResult&, ClickResult, bool, startedInteraction, bool, endedInteraction, bool, usingTool, bool, justActivated, bool, canUse);

