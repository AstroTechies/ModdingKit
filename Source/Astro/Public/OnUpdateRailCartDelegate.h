#pragma once
#include "CoreMinimal.h"
#include "OnUpdateRailCartDelegate.generated.h"

class APhysicalItem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdateRailCart, float, Alpha, APhysicalItem*, Item);

