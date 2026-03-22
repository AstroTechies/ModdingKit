#pragma once
#include "CoreMinimal.h"
#include "EAchievementSaveDataType.generated.h"

UENUM(BlueprintType)
enum class EAchievementSaveDataType : uint8 {
    PlayerSaveData,
    GameSaveData,
};

