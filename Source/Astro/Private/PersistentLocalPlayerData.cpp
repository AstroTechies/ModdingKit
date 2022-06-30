#include "PersistentLocalPlayerData.h"

void UPersistentLocalPlayerData::NotifySkippedTutorial() {
}

void UPersistentLocalPlayerData::NotifySeenIntroCutscene(bool wasUpdateCinematic) {
}

void UPersistentLocalPlayerData::NotifyCompletedTutorial() {
}

UPersistentLocalPlayerData::UPersistentLocalPlayerData() {
    this->bHasCompletedTutorial = false;
    this->bHasSkippedTutorial = false;
    this->bHasSeenIntroCutscene = false;
    this->bIsMultiplayerDisabled = false;
    this->LastUpdateCutsceneVersionSeen = 0;
}

