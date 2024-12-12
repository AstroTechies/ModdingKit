#pragma once
#include "CoreMinimal.h"
#include "PreDisconnectedDelegate.generated.h"

class ASlotConnection;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPreDisconnected, const ASlotConnection*, Connection);

