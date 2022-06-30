#pragma once
#include "CoreMinimal.h"
#include "PlanetaryGateObjectsState.generated.h"

class AAstroPlanet;

USTRUCT(BlueprintType)
struct FPlanetaryGateObjectsState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    AAstroPlanet* Planet;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bEngineActivated: 1;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    int32 NumChambersActivated;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ChamberActivationBitMask;
    
    ASTRO_API FPlanetaryGateObjectsState();
};

