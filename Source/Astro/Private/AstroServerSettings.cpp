#include "AstroServerSettings.h"

UAstroServerSettings::UAstroServerSettings() {
    this->MaxServerFramerate = 30.00f;
    this->MaxServerIdleFramerate = 3.00f;
    this->MaximumPlayerCount = 8;
    this->bLoadAutoSave = true;
    this->ExitSemaphore = TEXT("EXITREQUEST");
    this->bWaitForPlayersBeforeShutdown = false;
    this->ConsolePort = 1234;
    this->HeartbeatInterval = 55;
    this->OwnerGuid = 0;
    this->PlayerActivityTimeout = 0;
    this->bDisableServerTravel = false;
    this->DenyUnlistedPlayers = false;
    this->VerbosePlayerProperties = false;
    this->Dirty = false;
    this->AutoSaveGameInterval = 900;
    this->BackupSaveGamesInterval = 7200;
}


