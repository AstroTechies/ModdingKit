#include "ResourceCoreComponent.h"

UResourceCoreComponent::UResourceCoreComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ItemComponent = NULL;
    this->MeshComponent = NULL;
}

void UResourceCoreComponent::OnItemChange() {
}


