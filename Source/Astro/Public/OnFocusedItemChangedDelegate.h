#pragma once
#include "CoreMinimal.h"
#include "EFocusItemFocusChangeCause.h"
#include "OnFocusedItemChangedDelegate.generated.h"

class UAstroGameMenuFocusItemWidget;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFocusedItemChanged, UAstroGameMenuFocusItemWidget*, FocusItem, EFocusItemFocusChangeCause, FocusChangeCause);

