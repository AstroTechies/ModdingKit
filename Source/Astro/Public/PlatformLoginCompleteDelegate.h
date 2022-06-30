#pragma once
#include "CoreMinimal.h"
#include "PlatformLoginCompleteDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlatformLoginComplete, bool, Status);

