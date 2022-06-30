#pragma once
#include "CoreMinimal.h"
#include "EExoRequestStatus.generated.h"

UENUM(BlueprintType)
enum class EExoRequestStatus : uint8 {
    NoMission,
    MissionAvailable,
    WaitingForShip,
    ShipDocked,
    ShipOutgoing,
    ShipIncoming,
};

