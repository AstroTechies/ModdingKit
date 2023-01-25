#pragma once
#include "CoreMinimal.h"
#include "TestDelegateAstroDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FTestDelegateAstro, const FString&, InStr);

