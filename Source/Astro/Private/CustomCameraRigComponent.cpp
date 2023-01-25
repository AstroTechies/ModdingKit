#include "CustomCameraRigComponent.h"

class AActor;
class ACameraRigActor;
class UCustomCameraRigComponent;

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

UCustomCameraRigComponent::UCustomCameraRigComponent() {
    this->BehaviorContextClass = NULL;
    this->ActiveRig = NULL;
    this->ContextInstance = NULL;
}

