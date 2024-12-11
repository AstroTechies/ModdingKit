#include "ActorEntityLinkComponent.h"

UActorEntityLinkComponent::UActorEntityLinkComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UActorEntityLinkComponent::IsSpawnedFromEntity() const {
    return false;
}

FAstroDatumRef UActorEntityLinkComponent::GetEntityDatumRef(bool& bOutSuccess) const {
    return FAstroDatumRef{};
}


