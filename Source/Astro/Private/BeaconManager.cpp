#include "BeaconManager.h"

UBeaconManager::UBeaconManager() {
    this->GameStateCache = NULL;
    this->PlayControllerCache = NULL;
    this->AstroCharacterCache = NULL;
}

void UBeaconManager::OnLocalSolarBodyChanged(ASolarBody* newBody) {
}


