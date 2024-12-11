#pragma once
#include "CoreMinimal.h"
#include "PlanetaryGateObjectsState.h"
#include "GatesGameStateReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FGatesGameStateReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FPlanetaryGateObjectsState> PlanetaryGateObjectsStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bStationPresentInSolarSystem: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bStationActivated: 1;
    
    ASTRO_API FGatesGameStateReplicationData();
};

