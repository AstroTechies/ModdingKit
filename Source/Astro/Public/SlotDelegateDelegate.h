#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "SlotDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlotDelegate, FSlotReference, Slot);

