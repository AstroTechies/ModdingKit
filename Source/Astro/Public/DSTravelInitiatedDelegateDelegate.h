#pragma once
#include "CoreMinimal.h"
#include "DSTravelInitiatedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FDSTravelInitiatedDelegate, bool, success);

