#pragma once
#include "CoreMinimal.h"
#include "BackpackToggledDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBackpackToggledDelegate, bool, BackpackEnabled);

