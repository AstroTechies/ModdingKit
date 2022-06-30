#pragma once
#include "CoreMinimal.h"
#include "ProbeUnlockState.generated.h"

USTRUCT(BlueprintType)
struct FProbeUnlockState {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    uint64 CharacterId;
    
    UPROPERTY(SaveGame)
    TArray<FName> UnlockedProbes;
    
    ASTRO_API FProbeUnlockState();
};

