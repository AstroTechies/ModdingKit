#pragma once
#include "CoreMinimal.h"
#include "ConnectionDelegateDelegate.generated.h"

class UChildSlotComponent;
class ASlotConnection;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FConnectionDelegate, UChildSlotComponent*, Slot, ASlotConnection*, Connection);

