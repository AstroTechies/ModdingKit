#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ReceiveToolLocationDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceiveToolLocation, FTransform, Transform);

