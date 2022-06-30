#pragma once
#include "CoreMinimal.h"
#include "PoweredStateChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPoweredStateChanged, bool, Powered);

