#pragma once
#include "CoreMinimal.h"
#include "PlayerControllerRecord.generated.h"

USTRUCT(BlueprintType)
struct FPlayerControllerRecord {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ActorIndex;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 LastControlledPawn;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint64 NetworkUuid;
    
    ASTRO_API FPlayerControllerRecord();
};

