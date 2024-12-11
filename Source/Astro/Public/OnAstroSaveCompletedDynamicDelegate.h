#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=uint8 -FallbackName=uint8
#include "OnAstroSaveCompletedDynamicDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnAstroSaveCompletedDynamic, uint8, saveOperationResult, const FString&, Filename);

