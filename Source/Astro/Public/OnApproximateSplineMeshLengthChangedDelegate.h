#pragma once
#include "CoreMinimal.h"
#include "OnApproximateSplineMeshLengthChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnApproximateSplineMeshLengthChanged, float, ApproximateSplineMeshLength);

