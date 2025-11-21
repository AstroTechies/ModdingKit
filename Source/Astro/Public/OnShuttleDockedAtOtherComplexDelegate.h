#pragma once
#include "CoreMinimal.h"
#include "ELogisticsComplexChannel.h"
#include "OnShuttleDockedAtOtherComplexDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShuttleDockedAtOtherComplex, const ELogisticsComplexChannel, Channel);

