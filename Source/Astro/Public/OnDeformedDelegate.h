#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=DeformationParamsT2 -FallbackName=DeformationParamsT2
#include "DeformationParamsT2.h"
#include "OnDeformedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeformed, const FDeformationParamsT2&, deformationParams);

