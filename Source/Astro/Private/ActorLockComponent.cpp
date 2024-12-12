#include "ActorLockComponent.h"

UActorLockComponent::UActorLockComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
}

void UActorLockComponent::OnAuthorityLockingMechanismStateChanged(ULockingMechanism* changedLockingMechanism, const FLockChangedEventMetadata& EventData) {
}

void UActorLockComponent::OnAuthorityLockedStateChanged(FAstroDatumRef lockComponentRef, const FLockChangedEventMetadata& EventData) {
}


