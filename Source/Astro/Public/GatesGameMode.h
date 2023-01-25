#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroGameMode.h"
#include "GatesGameMode.generated.h"

class AAstroPlanet;
class AGateChamber;
class AGateEngine;
class AGateStation;
class USolarSystem;

UCLASS(Blueprintable, NonTransient)
class ASTRO_API AGatesGameMode : public AAstroGameMode {
    GENERATED_BODY()
public:
    AGatesGameMode();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AGateStation* TryGetGateStationActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AGateEngine* TryGetGateEngineActor(AAstroPlanet* enginePlanet) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AGateChamber* TryGetGateChamberActor(AAstroPlanet* chamberPlanet, int32 ChamberCoordinateIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StationSpawned();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StationActivated();
    
    UFUNCTION(BlueprintCallable)
    void OnStationSpawned();
    
    UFUNCTION(BlueprintCallable)
    void OnStationActivated(FAstroDatumRef stationEntityRef);
    
    UFUNCTION(BlueprintCallable)
    void OnEngineActivated(FAstroDatumRef engineEntityRef);
    
    UFUNCTION(BlueprintCallable)
    void OnChamberActivated(FAstroDatumRef chamberEntityRef);
    
    UFUNCTION(BlueprintCallable)
    void InitializeGatesForSolarSystem(USolarSystem* SolarSystem);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EngineActivated(AAstroPlanet* enginePlanet);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ChamberActivated(AAstroPlanet* chamberPlanet);
    
};

