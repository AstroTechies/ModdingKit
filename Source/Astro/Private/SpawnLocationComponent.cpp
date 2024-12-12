#include "SpawnLocationComponent.h"

USpawnLocationComponent::USpawnLocationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Spawn = NULL;
    this->IsEnabled = false;
    this->SpawnType = ESpawnPointType::Temporary;
}

void USpawnLocationComponent::PushSpawnLocation() {
}

void USpawnLocationComponent::PopSpawnLocation() {
}


