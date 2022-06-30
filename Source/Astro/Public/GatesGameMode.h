#pragma once
#include "CoreMinimal.h"
#include "AstroGameMode.h"
#include "AstroDatumRef.h"
#include "GatesGameMode.generated.h"

class AGateChamber;
class AGateStation;
class AGateEngine;
class AAstroPlanet;
class USolarSystem;

UCLASS(Blueprintable, NonTransient)
class ASTRO_API AGatesGameMode : public AAstroGameMode
{
    GENERATED_BODY()
public:
    AGatesGameMode();
    UFUNCTION(BlueprintPure)
    AGateStation *TryGetGateStationActor() const;

    UFUNCTION(BlueprintPure)
    AGateEngine *TryGetGateEngineActor(AAstroPlanet *enginePlanet) const;

    UFUNCTION(BlueprintPure)
    AGateChamber *TryGetGateChamberActor(AAstroPlanet *chamberPlanet, int32 ChamberCoordinateIndex) const;

    UFUNCTION(BlueprintImplementableEvent)
    void StationSpawned();

    UFUNCTION(BlueprintImplementableEvent)
    void StationActivated();

    UFUNCTION()
    void OnStationSpawned();

    UFUNCTION()
    void OnStationActivated(FAstroDatumRef stationEntityRef);

    UFUNCTION()
    void OnEngineActivated(FAstroDatumRef engineEntityRef);

    UFUNCTION()
    void OnChamberActivated(FAstroDatumRef chamberEntityRef);

    UFUNCTION()
    void InitializeGatesForSolarSystem(USolarSystem *SolarSystem);

    UFUNCTION(BlueprintImplementableEvent)
    void EngineActivated(AAstroPlanet *enginePlanet);

    UFUNCTION(BlueprintImplementableEvent)
    void ChamberActivated(AAstroPlanet *chamberPlanet);
};
