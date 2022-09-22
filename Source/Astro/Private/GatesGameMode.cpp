#include "GatesGameMode.h"

class AGateEngine;
class AGateStation;
class AAstroPlanet;
class AGateChamber;
class USolarSystem;

AGateStation* AGatesGameMode::TryGetGateStationActor() const {
    return NULL;
}

AGateEngine* AGatesGameMode::TryGetGateEngineActor(AAstroPlanet* enginePlanet) const {
    return NULL;
}

AGateChamber* AGatesGameMode::TryGetGateChamberActor(AAstroPlanet* chamberPlanet, int32 ChamberCoordinateIndex) const {
    return NULL;
}



void AGatesGameMode::OnStationSpawned() {
}

void AGatesGameMode::OnStationActivated(FAstroDatumRef stationEntityRef) {
}

void AGatesGameMode::OnEngineActivated(FAstroDatumRef engineEntityRef) {
}

void AGatesGameMode::OnChamberActivated(FAstroDatumRef chamberEntityRef) {
}

void AGatesGameMode::InitializeGatesForSolarSystem(USolarSystem* SolarSystem) {
}



AGatesGameMode::AGatesGameMode() {
}

