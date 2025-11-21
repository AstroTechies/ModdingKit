#include "BoxRemapComponent.h"

UBoxRemapComponent::UBoxRemapComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShapeBodySetup = NULL;
    this->RemappedActor = NULL;
}

void UBoxRemapComponent::SetRemappedActor(UChildActorComponent* remappedActorComponent) {
}


