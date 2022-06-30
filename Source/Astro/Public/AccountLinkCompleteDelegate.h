#pragma once
#include "CoreMinimal.h"
#include "AccountLinkCompleteDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAccountLinkComplete, bool, Status);

