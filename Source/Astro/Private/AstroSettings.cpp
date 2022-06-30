#include "AstroSettings.h"

class AAstroSettings;
class AActor;

AAstroSettings* AAstroSettings::GetAstroSettings(AActor* Actor) {
    return NULL;
}

AAstroSettings::AAstroSettings() {
    this->bIsFlatland = false;
    this->bFreePower = false;
    this->bInteractionLogging = false;
    this->bSurvival = true;
    this->bStartAllRecipes = true;
    this->bLoadAutoSave = false;
    this->bTrailer = false;
    this->bRelease = false;
    this->bBalancePalettes = false;
    this->bAnalyticsEnabled = true;
    this->IntroCinematicSequence = NULL;
    this->LatestUpdateCinematicSequence = NULL;
    this->OutroCinematicSequence = NULL;
    this->bGateStationPlacedAtRuntime = true;
    this->GateStationType = NULL;
    this->GateStationOrbitingBody = NULL;
    this->GateStationOrbitDistance = 100000.00f;
}

