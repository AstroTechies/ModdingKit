#pragma once
#include "CoreMinimal.h"
#include "OnFocusItemGenericInteractionDelegate.generated.h"

class UAstroGameMenuFocusItemWidget;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFocusItemGenericInteraction, UAstroGameMenuFocusItemWidget*, FocusItemWidget);

