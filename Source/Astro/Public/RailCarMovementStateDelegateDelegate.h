#pragma once
#include "CoreMinimal.h"
#include "ERailCarMovementState.h"
#include "RailCarMovementStateDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRailCarMovementStateDelegate, ERailCarMovementState, movementState);

