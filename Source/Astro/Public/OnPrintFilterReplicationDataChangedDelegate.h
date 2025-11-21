#pragma once
#include "CoreMinimal.h"
#include "PrintFilterReplicatedState.h"
#include "OnPrintFilterReplicationDataChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPrintFilterReplicationDataChanged, FPrintFilterReplicatedState, State);

