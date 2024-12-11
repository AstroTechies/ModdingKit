#include "ResourceType.h"
#include "Templates/SubclassOf.h"

UResourceType::UResourceType() {
}

UResourceType* UResourceType::ResourceTypeDefault(TSubclassOf<UResourceType> Class) {
    return NULL;
}


