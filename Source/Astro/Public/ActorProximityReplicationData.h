#pragma once
#include "CoreMinimal.h"
#include "ActorProximityReplicationData.generated.h"

class AActor;

USTRUCT(Atomic, BlueprintType)
struct FActorProximityReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasEncounteredActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsInProximity;
    
    ASTRO_API FActorProximityReplicationData();
};

