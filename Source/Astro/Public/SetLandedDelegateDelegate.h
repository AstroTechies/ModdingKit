#pragma once
#include "CoreMinimal.h"
#include "SetLandedDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetLandedDelegate, bool, Landed);

