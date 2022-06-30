#pragma once
#include "CoreMinimal.h"
#include "EAutoCraneTransferStage.generated.h"

UENUM(BlueprintType)
enum class EAutoCraneTransferStage : uint8 {
    PickupPending,
    PickupInProgress,
    TransferToDropoff,
    DropoffPending,
    DropoffInProgress,
    TransferToPickup,
};

