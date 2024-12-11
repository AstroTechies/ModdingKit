#pragma once
#include "CoreMinimal.h"
#include "OnLandedChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLandedChanged, bool, bIsLanded);

