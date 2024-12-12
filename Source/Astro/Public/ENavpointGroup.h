#pragma once
#include "CoreMinimal.h"
#include "ENavpointGroup.generated.h"

UENUM(BlueprintType)
enum class ENavpointGroup : uint8 {
    None,
    SnailBuff,
    SnailMission = 4,
    RailMissionsA = 8,
    RailMissionsA1,
    RailMissionsA2,
    RailMissionsB,
    RailMissionsB1,
    RailMissionsB2,
    RailMissionsC,
    ALTE_Puzzles,
};

