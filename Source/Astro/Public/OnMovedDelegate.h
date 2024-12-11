#pragma once
#include "CoreMinimal.h"
#include "OnMovedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoved, bool, FromTool);

