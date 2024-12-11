#pragma once
#include "CoreMinimal.h"
#include "EAstroPlayerStormRadiusStates.h"
#include "PlayerStormRadiusStateChangeDelegateDelegate.generated.h"

class AAstroPlayerController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayerStormRadiusStateChangeDelegate, AAstroPlayerController*, Player, EAstroPlayerStormRadiusStates, State);

