#pragma once
#include "CoreMinimal.h"
#include "ETeleportationBubbleState.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "TeleportationBubbleReplicationData.generated.h"

class AAstroPlanet;

USTRUCT(BlueprintType)
struct FTeleportationBubbleReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETeleportationBubbleState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PersistentTerrainObservationLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAstroPlanet* DestinationPlanet;
    
    ASTRO_API FTeleportationBubbleReplicationData();
};

