#pragma once
#include "CoreMinimal.h"
#include "PreDisconnectedDelegate.generated.h"

class ASlotConnection;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPreDisconnected, const ASlotConnection*, Connection);

