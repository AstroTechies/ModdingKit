#pragma once
#include "CoreMinimal.h"
#include "ERiftTrackerState.h"
#include "OnRiftTrackerStateChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRiftTrackerStateChanged, ERiftTrackerState, NewState);

