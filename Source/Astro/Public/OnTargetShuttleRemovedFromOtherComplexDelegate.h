#pragma once
#include "CoreMinimal.h"
#include "ELogisticsComplexChannel.h"
#include "OnTargetShuttleRemovedFromOtherComplexDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetShuttleRemovedFromOtherComplex, const ELogisticsComplexChannel, Channel);

