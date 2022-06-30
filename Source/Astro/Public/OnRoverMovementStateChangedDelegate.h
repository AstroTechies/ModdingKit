#pragma once
#include "CoreMinimal.h"
#include "OnRoverMovementStateChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoverMovementStateChanged, bool, bIsMoving);

