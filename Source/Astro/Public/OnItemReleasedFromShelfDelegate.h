#pragma once
#include "CoreMinimal.h"
#include "OnItemReleasedFromShelfDelegate.generated.h"

class APhysicalItem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemReleasedFromShelf, APhysicalItem*, inItem);

