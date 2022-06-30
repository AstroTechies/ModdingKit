#include "ChildPhysicalItemComponent.h"

class APhysicalItem;

APhysicalItem* UChildPhysicalItemComponent::GetChildPhysicalItem() {
    return NULL;
}

UChildPhysicalItemComponent::UChildPhysicalItemComponent() {
    this->ChildMovableItemClass = NULL;
    this->TerrainMode = EPhysicalItemTerrainMode::Attach;
}

