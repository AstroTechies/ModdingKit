#pragma once
#include "CoreMinimal.h"
#include "EPhysicalItemMotionState.h"
#include "OnMotionStateChangedExtendedInfoDelegate.generated.h"

class APhysicalItem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMotionStateChangedExtendedInfo, APhysicalItem*, Item, EPhysicalItemMotionState, newMotionState);

