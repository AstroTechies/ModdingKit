#pragma once
#include "CoreMinimal.h"
#include "EFocusItemFocusChangeCause.h"
#include "OnFocusItemFocusStateChangedDelegate.generated.h"

class UAstroGameMenuFocusItemWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnFocusItemFocusStateChanged, bool, NewIsFocused, UAstroGameMenuFocusItemWidget*, FocusableWidget, EFocusItemFocusChangeCause, FocusChangeCause);

