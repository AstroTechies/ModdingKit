#include "BeaconManager.h"

class ASolarBody;

void UBeaconManager::OnLocalSolarBodyChanged(ASolarBody* newBody) {
}

UBeaconManager::UBeaconManager() {
    this->GameStateCache = NULL;
    this->PlayControllerCache = NULL;
    this->AstroCharacterCache = NULL;
}

