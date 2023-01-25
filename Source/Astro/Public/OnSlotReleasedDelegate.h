#pragma once
#include "CoreMinimal.h"
#include "OnSlotReleasedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotReleased, bool, NewOwner);

