#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "OnEditingItemUnhandledKeyPressDelegate.generated.h"

class UAstroGameMenuFocusItemWidget;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEditingItemUnhandledKeyPress, FKey, KeyPressed, UAstroGameMenuFocusItemWidget*, FocusableWidget);

