#pragma once
#include "CoreMinimal.h"
#include "EItemRetrievalQuantityFilter.generated.h"

UENUM()
enum class EItemRetrievalQuantityFilter : uint8 {
    OnlyFullItem,
    OnlyPartialItem,
    FullOrPartialItem,
};

