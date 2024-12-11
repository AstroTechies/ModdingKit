#pragma once
#include "CoreMinimal.h"
#include "OnActionEndedDelegate.generated.h"

class UAstroAction;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActionEnded, UAstroAction*, EndedAction);

