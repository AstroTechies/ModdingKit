#include "ActorLockComponent.h"

UActorLockComponent::UActorLockComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UActorLockComponent::OnAuthorityLockingMechanismStateChanged(ULockingMechanism* changedLockingMechanism, const FLockChangedEventMetadata& EventData) {
}

void UActorLockComponent::OnAuthorityLockedStateChanged(FAstroDatumRef lockComponentRef, const FLockChangedEventMetadata& EventData) {
}


