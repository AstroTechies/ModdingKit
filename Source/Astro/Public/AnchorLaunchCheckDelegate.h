#pragma once
#include "CoreMinimal.h"
#include "AnchorLaunchCheckDelegate.generated.h"

class APhysicalItem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAnchorLaunchCheck, bool, bCanLaunch, APhysicalItem*, destinationLandingPad);

