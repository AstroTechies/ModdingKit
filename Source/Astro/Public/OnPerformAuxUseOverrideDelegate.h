#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "OnPerformAuxUseOverrideDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPerformAuxUseOverride, TEnumAsByte<EInputEvent>, InputEvent);

