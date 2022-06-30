#pragma once
#include "CoreMinimal.h"
#include "OnCurrentResearchPointBalanceChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrentResearchPointBalanceChanged, float, NewPointBalance);

