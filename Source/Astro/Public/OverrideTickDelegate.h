#pragma once
#include "CoreMinimal.h"
#include "OverrideTickDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOverrideTick, float, DeltaTime);

