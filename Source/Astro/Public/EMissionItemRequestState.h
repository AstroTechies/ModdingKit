#pragma once
#include "CoreMinimal.h"
#include "EMissionItemRequestState.generated.h"

UENUM(BlueprintType)
enum class EMissionItemRequestState : uint8 {
    RequestsUninitalized,
    HasNoActiveRequests,
    HasActiveRequests,
    ConsumptionInProgress,
};

