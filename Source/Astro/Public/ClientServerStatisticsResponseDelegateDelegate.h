#pragma once
#include "CoreMinimal.h"
#include "ServerStatistics.h"
#include "ClientServerStatisticsResponseDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClientServerStatisticsResponseDelegate, const FServerStatistics&, ServerStatistics);

