#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESaveGameOperationResult -FallbackName=ESaveGameOperationResult
#include "OnAstroSaveCompletedDynamicDelegate.generated.h"

UENUM()
enum class ESaveGameOperationResult : uint8 {
	Success = 0,
	ErrorNotEnoughSpace = 1,
	ErrorUnspecified = 2,
	ESaveGameOperationResult_MAX = 3
};

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAstroSaveCompletedDynamic, ESaveGameOperationResult, saveOperationResult);

