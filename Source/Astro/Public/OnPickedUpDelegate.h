#pragma once
#include "CoreMinimal.h"
#include "OnPickedUpDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickedUp, bool, PhysicalMovement);

