#include "PhysicalItemSpawnList.h"
#include "Templates/SubclassOf.h"

class APhysicalItem;
class UPhysicalItemSpawnList;

TSubclassOf<APhysicalItem> UPhysicalItemSpawnList::PickActor() {
    return NULL;
}

UPhysicalItemSpawnList* UPhysicalItemSpawnList::PhysicalItemSpawnListDefault(TSubclassOf<UPhysicalItemSpawnList> Type) {
    return NULL;
}

UPhysicalItemSpawnList::UPhysicalItemSpawnList() {
}

