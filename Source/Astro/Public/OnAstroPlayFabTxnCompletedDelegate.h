#pragma once
#include "CoreMinimal.h"
#include "OnAstroPlayFabTxnCompletedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAstroPlayFabTxnCompleted, bool, bSuccess);

