#pragma once
#include "CoreMinimal.h"
#include "PlayFabPPlayerStatisticRefreshedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayFabPPlayerStatisticRefreshedDelegate, int32, Value);

