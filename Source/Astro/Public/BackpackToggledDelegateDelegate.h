#pragma once
#include "CoreMinimal.h"
#include "BackpackToggledDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBackpackToggledDelegate, bool, BackpackEnabled);

