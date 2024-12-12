#include "ActorResearchPointGrantComponent.h"

UActorResearchPointGrantComponent::UActorResearchPointGrantComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MinPointsGranted = 10.00f;
    this->MaxPointsGranted = 20.00f;
}


