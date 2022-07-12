#pragma once
#include "CoreMinimal.h"
#include "ProbeUnlockState.generated.h"

USTRUCT(BlueprintType)
struct FProbeUnlockState {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame)
    uint64 CharacterId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> UnlockedProbes;
    
    ASTRO_API FProbeUnlockState();
};

