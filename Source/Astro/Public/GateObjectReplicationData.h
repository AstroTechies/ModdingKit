#pragma once
#include "CoreMinimal.h"
#include "GateObjectReplicationData.generated.h"

class AAstroCharacter;

USTRUCT(Atomic, BlueprintType)
struct FGateObjectReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool bHasBeenInitialized;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool bCanBeActivated;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool bIsActivated;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool bHasEncounteredPlayer;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<AAstroCharacter*> PlayerCharactersInProximity;
    
    ASTRO_API FGateObjectReplicationData();
};

