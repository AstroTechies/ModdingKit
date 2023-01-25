#pragma once
#include "CoreMinimal.h"
#include "DrillAudioEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDrillAudioEvent, int32, AudioEventIndex);

