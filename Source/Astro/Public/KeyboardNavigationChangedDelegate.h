#pragma once
#include "CoreMinimal.h"
#include "KeyboardNavigationChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FKeyboardNavigationChanged, bool, bUsingKeyboardNavigation);

