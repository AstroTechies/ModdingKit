#pragma once
#include "CoreMinimal.h"
#include "ESaveGameErrorType.generated.h"

UENUM(BlueprintType)
enum class ESaveGameErrorType : uint8 {
    NoError,
    LastAttemptToSaveFailedDueToInsufficientStorage,
    LastAttemptToSaveFailedExceededMaxFileSize,
    UnknownError,
};

