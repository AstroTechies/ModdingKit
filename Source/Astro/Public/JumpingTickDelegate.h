#pragma once
#include "CoreMinimal.h"
#include "JumpingTickDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJumpingTick, float, DeltaTime);

