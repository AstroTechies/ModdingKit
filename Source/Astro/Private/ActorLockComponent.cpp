#include "ActorLockComponent.h"

class ULockingMechanism;

void UActorLockComponent::OnAuthorityLockingMechanismStateChanged(ULockingMechanism* changedLockingMechanism, const FLockChangedEventMetadata& EventData) {
}

void UActorLockComponent::OnAuthorityLockedStateChanged(FAstroDatumRef lockComponentRef, const FLockChangedEventMetadata& EventData) {
}

UActorLockComponent::UActorLockComponent() {
}

