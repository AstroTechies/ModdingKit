#include "ActorEntityLinkComponent.h"

bool UActorEntityLinkComponent::IsSpawnedFromEntity() const {
    return false;
}

FAstroDatumRef UActorEntityLinkComponent::GetEntityDatumRef(bool& bOutSuccess) const {
    return FAstroDatumRef{};
}

UActorEntityLinkComponent::UActorEntityLinkComponent() {
}

