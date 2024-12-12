#pragma once
#include "CoreMinimal.h"
#include "OnDummyDrillRemovedDelegate.generated.h"

class AVehicleDrill;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDummyDrillRemoved, AVehicleDrill*, DummyDrill);

