#pragma once
#include "CoreMinimal.h"
#include "ActiveItemConversion.h"
#include "ActiveItemConversionEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActiveItemConversionEvent, const FActiveItemConversion&, activeConversion);

