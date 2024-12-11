#include "ChildPhysicalItemComponent.h"

UChildPhysicalItemComponent::UChildPhysicalItemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ChildMovableItemClass = NULL;
    this->TerrainMode = EPhysicalItemTerrainMode::Attach;
}

APhysicalItem* UChildPhysicalItemComponent::GetChildPhysicalItem() {
    return NULL;
}


