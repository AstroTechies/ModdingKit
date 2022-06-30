#include "ResourceType.h"
#include "Templates/SubclassOf.h"

class UResourceType;

UResourceType* UResourceType::ResourceTypeDefault(TSubclassOf<UResourceType> Class) {
    return NULL;
}

UResourceType::UResourceType() {
}

