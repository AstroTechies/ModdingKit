#include "AstroStormSpawnLocationCandidate.h"

AAstroStormSpawnLocationCandidate::AAstroStormSpawnLocationCandidate(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StormClass = NULL;
    this->ActiveStorm = NULL;
    this->ActiveStormID = -1;
    this->FixedStormID = 0;
    this->IsEnabled = true;
    this->IsBossStorm = false;
}

AAstroStorm* AAstroStormSpawnLocationCandidate::SpawnStorm(int32 StormID, int32 StateIndex) {
    return NULL;
}

void AAstroStormSpawnLocationCandidate::SetEnabled(bool NewIsEnabled) {
}

void AAstroStormSpawnLocationCandidate::OnGlitchWalkersFinalEncounterStarted_Implementation() {
}

void AAstroStormSpawnLocationCandidate::OnGlitchWalkersFinalEncounterReset_Implementation() {
}

void AAstroStormSpawnLocationCandidate::OnGlitchWalkersFinalEncounterCompleted_Implementation() {
}

void AAstroStormSpawnLocationCandidate::Destroyed() {
}

int32 AAstroStormSpawnLocationCandidate::ClearStorm() {
    return 0;
}

void AAstroStormSpawnLocationCandidate::BeginPlay() {
}


