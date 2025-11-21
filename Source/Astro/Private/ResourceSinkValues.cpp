#include "ResourceSinkValues.h"
#include "Templates/SubclassOf.h"

UResourceSinkValues::UResourceSinkValues() {
}

int32 UResourceSinkValues::GetScoreBySeedItemType(const TSubclassOf<UItemType>& ItemType) {
    return 0;
}

int32 UResourceSinkValues::GetScoreByResourceItemType(const TSubclassOf<UItemType>& ItemType) {
    return 0;
}


