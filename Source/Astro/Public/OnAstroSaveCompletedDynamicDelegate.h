#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESaveGameOperationResult -FallbackName=ESaveGameOperationResult
#include "OnAstroSaveCompletedDynamicDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAstroSaveCompletedDynamic, uint8, saveOperationResult);

