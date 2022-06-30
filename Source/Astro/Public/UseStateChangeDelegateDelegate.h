#pragma once
#include "CoreMinimal.h"
#include "UseStateChangeDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUseStateChangeDelegate, bool, IsUsable);

