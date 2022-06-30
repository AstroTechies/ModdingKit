#pragma once
#include "CoreMinimal.h"
#include "EMissionItemRequestState.generated.h"

UENUM()
enum class EMissionItemRequestState : uint8 {
    RequestsUninitalized,
    HasNoActiveRequests,
    HasActiveRequests,
    ConsumptionInProgress,
};

