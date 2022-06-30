#pragma once
#include "CoreMinimal.h"
#include "DeformTargetSignalDelegate.generated.h"

class AActor;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeformTargetSignal, AActor*, Deformer);

