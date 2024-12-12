#pragma once
#include "CoreMinimal.h"
#include "OnReceivedInitialThemeActiveStatusDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReceivedInitialThemeActiveStatus, TArray<FName>, activeThemeOfInterest);

