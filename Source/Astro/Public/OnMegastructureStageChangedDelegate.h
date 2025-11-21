#pragma once
#include "CoreMinimal.h"
#include "OnMegastructureStageChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMegastructureStageChanged, int32, NewStage);

