#pragma once
#include "CoreMinimal.h"
#include "UpdateCanLaunchSignalDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUpdateCanLaunchSignal, bool, Can, bool, Orbiting);

