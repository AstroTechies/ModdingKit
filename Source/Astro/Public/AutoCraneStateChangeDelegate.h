#pragma once
#include "CoreMinimal.h"
#include "AutoCraneStateChangeDelegate.generated.h"

class AAutoCrane;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAutoCraneStateChange, AAutoCrane*, Crane);

