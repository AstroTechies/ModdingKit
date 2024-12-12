#pragma once
#include "CoreMinimal.h"
#include "OnSnailFedChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSnailFedChanged, bool, bIsFed);

