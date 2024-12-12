#pragma once
#include "CoreMinimal.h"
#include "ClickableDelegateNewDelegate.generated.h"

class UClickQuery;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClickableDelegateNew, UClickQuery*, Query);

