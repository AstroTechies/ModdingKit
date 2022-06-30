#pragma once
#include "CoreMinimal.h"
#include "ViewDataChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FViewDataChanged, bool, force);

