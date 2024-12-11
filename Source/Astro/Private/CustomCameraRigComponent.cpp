#include "CustomCameraRigComponent.h"

UCustomCameraRigComponent::UCustomCameraRigComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BehaviorContextClass = NULL;
    this->ActiveRig = NULL;
    this->ContextInstance = NULL;
}

void UCustomCameraRigComponent::SetMode(FName Mode, const FViewTargetTransitionParams& params) {
}

FName UCustomCameraRigComponent::GetModeName() const {
    return NAME_None;
}

ACameraRigActor* UCustomCameraRigComponent::GetCameraRigForMode(const FName Mode) const {
    return NULL;
}

UCustomCameraRigComponent* UCustomCameraRigComponent::ActorCustomCameraRig(AActor* Actor) {
    return NULL;
}


