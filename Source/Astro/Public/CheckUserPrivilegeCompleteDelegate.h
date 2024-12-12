#pragma once
#include "CoreMinimal.h"
#include "CheckUserPrivilegeCompleteDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FCheckUserPrivilegeComplete, bool, succes);

