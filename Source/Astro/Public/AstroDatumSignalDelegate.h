#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroDatumSignalDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAstroDatumSignal, FAstroDatumRef, InstigatingDatumRef);

