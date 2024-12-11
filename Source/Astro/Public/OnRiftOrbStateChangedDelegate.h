#pragma once
#include "CoreMinimal.h"
#include "ERiftOrbState.h"
#include "OnRiftOrbStateChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRiftOrbStateChanged, ERiftOrbState, NewState);

