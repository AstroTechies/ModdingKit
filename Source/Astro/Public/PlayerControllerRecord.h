#pragma once
#include "CoreMinimal.h"
#include "PlayerControllerRecord.generated.h"

USTRUCT(BlueprintType)
struct FPlayerControllerRecord {
    GENERATED_BODY()
public:
    UPROPERTY()
    uint32 ActorIndex;
    
    UPROPERTY()
    uint32 LastControlledPawn;
    
    UPROPERTY()
    uint64 NetworkUuid;
    
    ASTRO_API FPlayerControllerRecord();
};

