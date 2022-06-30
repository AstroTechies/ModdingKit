#include "SpawnLocationComponent.h"

void USpawnLocationComponent::PushSpawnLocation() {
}

void USpawnLocationComponent::PopSpawnLocation() {
}

USpawnLocationComponent::USpawnLocationComponent() {
    this->Spawn = NULL;
    this->IsEnabled = false;
    this->SpawnType = ESpawnPointType::Temporary;
}

