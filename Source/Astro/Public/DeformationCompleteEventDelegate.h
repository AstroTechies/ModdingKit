#pragma once
#include "CoreMinimal.h"
#include "DeformationParamsT2.h"
#include "DeformationCompleteEventDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeformationCompleteEvent, const FDeformationParamsT2&, params);

