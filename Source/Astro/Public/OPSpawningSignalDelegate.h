#pragma once
#include "CoreMinimal.h"
#include "OPSpawningSignalDelegate.generated.h"

class AWreck;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOPSpawningSignal, AWreck*, Wreck);

