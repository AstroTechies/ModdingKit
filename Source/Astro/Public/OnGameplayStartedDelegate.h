#pragma once
#include "CoreMinimal.h"
#include "OnGameplayStartedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameplayStarted, bool, StartedInExistingSavedGame);

