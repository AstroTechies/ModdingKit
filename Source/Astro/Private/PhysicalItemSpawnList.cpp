#include "PhysicalItemSpawnList.h"
#include "Templates/SubclassOf.h"

UPhysicalItemSpawnList::UPhysicalItemSpawnList() {
}

TSubclassOf<APhysicalItem> UPhysicalItemSpawnList::PickActor() {
    return NULL;
}

UPhysicalItemSpawnList* UPhysicalItemSpawnList::PhysicalItemSpawnListDefault(TSubclassOf<UPhysicalItemSpawnList> Type) {
    return NULL;
}


