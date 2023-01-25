#pragma once
#include "CoreMinimal.h"
#include "DeformationParamsT2.h"
#include "OnDeformedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeformed, const FDeformationParamsT2&, deformationParams);

