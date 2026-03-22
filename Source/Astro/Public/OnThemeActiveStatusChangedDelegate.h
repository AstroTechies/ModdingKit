#pragma once
#include "CoreMinimal.h"
#include "OnThemeActiveStatusChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnThemeActiveStatusChanged, FName, EventName, bool, bIsThemeActive);

