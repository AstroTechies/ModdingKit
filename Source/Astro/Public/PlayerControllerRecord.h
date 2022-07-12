#pragma once
#include "CoreMinimal.h"
#include "PlayerControllerRecord.generated.h"

USTRUCT(BlueprintType)
struct FPlayerControllerRecord {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint32 ActorIndex;
    
    UPROPERTY(EditAnywhere)
    uint32 LastControlledPawn;
    
    UPROPERTY(EditAnywhere)
    uint64 NetworkUuid;
    
    ASTRO_API FPlayerControllerRecord();
};

