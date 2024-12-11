#pragma once
#include "CoreMinimal.h"
#include "GateObjectReference.h"
#include "GateObjectActivationSignalDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGateObjectActivationSignal, const FGateObjectReference&, ActivatedGateObjectRef);

