#pragma once
#include "CoreMinimal.h"
#include "EWandererRealityTearOpenState.h"
#include "WanderRealityTearOpenStateEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWanderRealityTearOpenStateEvent, EWandererRealityTearOpenState, State);

