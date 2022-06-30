#pragma once
#include "CoreMinimal.h"
#include "DSTravelInitiatedDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_OneParam(FDSTravelInitiatedDelegate, bool, success);

