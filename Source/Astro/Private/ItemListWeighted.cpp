#include "ItemListWeighted.h"
#include "Templates/SubclassOf.h"

class UItemListWeighted;
class UItemType;

TSubclassOf<UItemType> UItemListWeighted::PickItem() {
    return NULL;
}

UItemListWeighted* UItemListWeighted::ItemSpawnListDefault(TSubclassOf<UItemListWeighted> Type) {
    return NULL;
}

UItemListWeighted::UItemListWeighted() {
}

