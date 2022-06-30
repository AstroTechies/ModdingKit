#pragma once
#include "CoreMinimal.h"
#include "OnAstroRenameSaveCompletedDynamicDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnAstroRenameSaveCompletedDynamic, bool, renamedFileSaveSuccess, bool, oldFileDeleteSuccess);

