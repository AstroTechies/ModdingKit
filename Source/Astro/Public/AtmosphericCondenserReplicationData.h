#pragma once
#include "CoreMinimal.h"
#include "AtmosphericResource.h"
#include "EAtmosphericCondenserState.h"
#include "AtmosphericCondenserReplicationData.generated.h"

class AAstroPlanet;

USTRUCT(BlueprintType)
struct FAtmosphericCondenserReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EAtmosphericCondenserState CondenserState;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 SelectedOuputResourceIndex;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 NumPossibleProductionOutputs;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float ProductionEfficiency;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float ProductionPowerRatio;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FAtmosphericResource CurrentAtmosphericResource;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float CurrentHarvestedAtmosphereAmount;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    AAstroPlanet* CurrentPlanet;
    
    ASTRO_API FAtmosphericCondenserReplicationData();
};

