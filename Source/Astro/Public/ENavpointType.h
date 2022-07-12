#pragma once
#include "CoreMinimal.h"
#include "ENavpointType.generated.h"

UENUM(BlueprintType)
enum class ENavpointType : uint8 {
    None,
    Rover,
    Shuttle,
    Shelter,
    Player,
    POI,
    ActiveGateChamber,
    Corpse,
    Beacon,
    Probe,
    Mission,
    DataCache,
    Flora,
    Snail,
    Deposit,
};

