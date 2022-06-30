#pragma once
#include "CoreMinimal.h"
#include "PlatformLogoutCompleteDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlatformLogoutComplete, bool, Status);

