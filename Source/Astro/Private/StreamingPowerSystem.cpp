#include "StreamingPowerSystem.h"

UStreamingPowerSystem::UStreamingPowerSystem() {
    this->TaskManager = NULL;
}

void UStreamingPowerSystem::SplitMergedConnectionBetweenStreamingPowerNodesOnActors(AActor* thisActor, AActor* OtherActor) {
}

bool UStreamingPowerSystem::RemovePoweredItemFromActorsPowerNode(AActor* gridNodeOwner, AActor* OtherActor) {
    return false;
}

void UStreamingPowerSystem::CreateMergedConnectionBetweenStreamingPowerNodesOnActors(AActor* thisActor, AActor* OtherActor) {
}

bool UStreamingPowerSystem::AddPoweredItemToActorsPowerNode(AActor* gridNodeOwner, AActor* OtherActor) {
    return false;
}


