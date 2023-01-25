#pragma once
#include "CoreMinimal.h"
#include "OnFocusItemIsLastUsedStateChangedDelegate.generated.h"

class UAstroGameMenuFocusItemWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFocusItemIsLastUsedStateChanged, bool, NewLastUsed, UAstroGameMenuFocusItemWidget*, FocusableWidget);

