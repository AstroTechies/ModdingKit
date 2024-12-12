#pragma once
#include "CoreMinimal.h"
#include "EGameLifecycleState.h"
#include "OnGameLifecycleStateChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameLifecycleStateChanged, EGameLifecycleState, OldState, EGameLifecycleState, NewState);

