#include "ActorLockableComponent.h"

UActorLockableComponent::UActorLockableComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UActorLockableComponent::OnAuthorityLockedStateChanged(FAstroDatumRef lockableComponentRef, const FLockChangedEventMetadata& EventData) {
}


