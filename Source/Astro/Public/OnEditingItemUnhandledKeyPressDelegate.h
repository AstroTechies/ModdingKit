#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "OnEditingItemUnhandledKeyPressDelegate.generated.h"

class UAstroGameMenuFocusItemWidget;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEditingItemUnhandledKeyPress, FKey, KeyPressed, UAstroGameMenuFocusItemWidget*, FocusableWidget);

