#pragma once
#include "CoreMinimal.h"
#include "OnGameplayStartedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameplayStarted, bool, StartedInExistingSavedGame);

