#pragma once
#include "CoreMinimal.h"
#include "OxygenChangeDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOxygenChangeDelegate, bool, Oxygen);

