#include "CraftingOriginDependencyMap.h"

FCraftingOriginDependencyMap::FCraftingOriginDependencyMap() {
    this->CraftingDependency = ECraftingOrgin::None;
    this->bHasCraftingSources = false;
    this->UnsourcedCraftables = NULL;
}

