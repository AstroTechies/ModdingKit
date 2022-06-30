#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "EGateObjectType.h"
#include "AstroDatumRef.h"
#include "GateObjectComponent.generated.h"

class AAstroCharacter;
class UGateObjectEventListener;

USTRUCT(BlueprintType)
struct FGateObjectComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    EGateObjectType Type;
    
    UPROPERTY(SaveGame)
    uint8 bCanBeActivated: 1;
    
    UPROPERTY(SaveGame)
    uint8 bIsActivated: 1;
    
    UPROPERTY(SaveGame)
    uint8 bHasEncounteredPlayer: 1;
    
    UPROPERTY(SaveGame)
    int32 ChamberCoordinateIndex;
    
    UPROPERTY(SaveGame)
    TArray<FAstroDatumRef> GateObjectNetworkNeighborEntities;
    
    UPROPERTY(SaveGame)
    TArray<AAstroCharacter*> PlayerCharactersInProximity;
    
    UPROPERTY(SaveGame)
    UGateObjectEventListener* EventListener;
    
    ASTRO_API FGateObjectComponent();
};

