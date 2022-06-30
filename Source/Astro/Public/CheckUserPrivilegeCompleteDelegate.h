#pragma once
#include "CoreMinimal.h"
#include "CheckUserPrivilegeCompleteDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_OneParam(FCheckUserPrivilegeComplete, bool, succes);

