#pragma once
#include "CoreMinimal.h"
#include "ETeleportationBubbleState.h"
#include "UObject/NoExportTypes.h"
#include "TeleportationBubbleReplicationData.generated.h"

class AAstroPlanet;

USTRUCT(BlueprintType)
struct FTeleportationBubbleReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY()
    ETeleportationBubbleState State;
    
    UPROPERTY()
    FVector PersistentTerrainObservationLocation;
    
    UPROPERTY()
    AAstroPlanet* DestinationPlanet;
    
    ASTRO_API FTeleportationBubbleReplicationData();
};

