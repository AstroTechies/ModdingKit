#pragma once
#include "CoreMinimal.h"
#include "OnReplicationDataChangedDelegate.generated.h"

class APhysicalItem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReplicationDataChanged, APhysicalItem*, Item);

