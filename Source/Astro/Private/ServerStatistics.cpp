#include "ServerStatistics.h"

FServerStatistics::FServerStatistics() {
    this->MaxInGamePlayers = 0;
    this->PlayersInGame = 0;
    this->PlayersKnownToGame = 0;
    this->PlayerActivityTimeout = 0;
    this->SecondsInGame = 0;
    this->AverageFPS = 0.00f;
    this->HasServerPassword = false;
    this->IsEnforcingWhitelist = false;
    this->CreativeMode = false;
    this->IsAchievementProgressionDisabled = false;
}

