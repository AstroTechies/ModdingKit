#include "ItemListWeighted.h"
#include "Templates/SubclassOf.h"

UItemListWeighted::UItemListWeighted() {
}

TSubclassOf<UItemType> UItemListWeighted::PickItem() {
    return NULL;
}

UItemListWeighted* UItemListWeighted::ItemSpawnListDefault(TSubclassOf<UItemListWeighted> Type) {
    return NULL;
}


