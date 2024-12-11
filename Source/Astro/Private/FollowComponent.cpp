#include "FollowComponent.h"

UFollowComponent::UFollowComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FollowComponent = NULL;
    this->TrackFollowVelocity = true;
    this->ScaleComponent = NULL;
    this->TargetScale = 50.00f;
    this->ForceMultiplier = 6000.00f;
    this->ForceDampening = 4.00f;
    this->ArriveRadius = 50.00f;
    this->MinLife = 1.20f;
    this->MaxLife = 1.80f;
}

void UFollowComponent::SetFollowComponent(USceneComponent* Component) {
}

UFollowComponent* UFollowComponent::AddActorFollowComponent(AActor* Actor) {
    return NULL;
}


