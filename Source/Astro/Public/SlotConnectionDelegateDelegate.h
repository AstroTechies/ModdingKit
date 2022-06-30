#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "SlotConnectionDelegateDelegate.generated.h"

class ASlotConnection;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSlotConnectionDelegate, FSlotReference, Slot, ASlotConnection*, Connection);

