#include "PersistentLocalPlayerData.h"

UPersistentLocalPlayerData::UPersistentLocalPlayerData() {
    this->bHasCompletedTutorial = false;
    this->bHasSkippedTutorial = false;
    this->bHasSeenIntroCutscene = false;
    this->bIsMultiplayerDisabled = false;
    this->LastUpdateCutsceneVersionSeen = 0;
}

void UPersistentLocalPlayerData::NotifySkippedTutorial() {
}

void UPersistentLocalPlayerData::NotifySeenIntroCutscene(bool wasUpdateCinematic) {
}

void UPersistentLocalPlayerData::NotifyCompletedTutorial() {
}


