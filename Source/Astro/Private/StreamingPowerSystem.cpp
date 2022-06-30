#include "StreamingPowerSystem.h"

class AActor;

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

UStreamingPowerSystem::UStreamingPowerSystem() {
    this->TaskManager = NULL;
}

